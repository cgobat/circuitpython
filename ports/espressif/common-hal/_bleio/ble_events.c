/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Dan Halbert for Adafruit Industries
 * Copyright (c) 2018 Artur Pacholec
 * Copyright (c) 2016 Glenn Ruben Bakke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "common-hal/_bleio/ble_events.h"

#include <stdbool.h>
#include <stdio.h>

#include "py/gc.h"
#include "py/misc.h"
#include "py/mpstate.h"
#include "py/runtime.h"

#if CIRCUITPY_SERIAL_BLE && CIRCUITPY_VERBOSE_BLE
#include "supervisor/shared/bluetooth/serial.h"
#endif

void ble_event_reset(void) {
    // Linked list items will be gc'd.
    MP_STATE_VM(ble_event_handler_entries) = NULL;
}

void ble_event_remove_heap_handlers(void) {
    ble_event_handler_entry_t *it = MP_STATE_VM(ble_event_handler_entries);
    while (it != NULL) {
        // If the param is on the heap, then delete the handler.
        if (HEAP_PTR(it->param)) {
            ble_event_remove_handler(it->func, it->param);
        }
        it = it->next;
    }
}

void ble_event_add_handler_entry(ble_event_handler_entry_t *entry,
    ble_gap_event_fn *func, void *param) {
    ble_event_handler_entry_t *it = MP_STATE_VM(ble_event_handler_entries);
    while (it != NULL) {
        // If event handler and its corresponding param are already on the list, don't add again.
        if ((it->func == func) && (it->param == param)) {
            return;
        }
        it = it->next;
    }
    entry->next = MP_STATE_VM(ble_event_handler_entries);
    entry->param = param;
    entry->func = func;

    MP_STATE_VM(ble_event_handler_entries) = entry;
}

void ble_event_add_handler(ble_gap_event_fn *func, void *param) {
    ble_event_handler_entry_t *it = MP_STATE_VM(ble_event_handler_entries);
    while (it != NULL) {
        // If event handler and its corresponding param are already on the list, don't add again.
        if ((it->func == func) && (it->param == param)) {
            return;
        }
        it = it->next;
    }

    // Add a new handler to the front of the list
    ble_event_handler_entry_t *handler = m_new_ll(ble_event_handler_entry_t, 1);
    ble_event_add_handler_entry(handler, func, param);
}

void ble_event_remove_handler(ble_gap_event_fn *func, void *param) {
    ble_event_handler_entry_t *it = MP_STATE_VM(ble_event_handler_entries);
    ble_event_handler_entry_t **prev = &MP_STATE_VM(ble_event_handler_entries);
    while (it != NULL) {
        if ((it->func == func) && (it->param == param)) {
            // Splice out the matching handler.
            *prev = it->next;
            // Clear next of the removed node so it's clearly not in a list.
            it->next = NULL;
            return;
        }
        prev = &(it->next);
        it = it->next;
    }
}

int ble_event_run_handlers(struct ble_gap_event *event) {
    #if CIRCUITPY_SERIAL_BLE && CIRCUITPY_VERBOSE_BLE
    ble_serial_disable();
    #endif

    #if CIRCUITPY_VERBOSE_BLE
    mp_printf(&mp_plat_print, "BLE GAP event: 0x%04x\n", event->type);
    #endif

    ble_event_handler_entry_t *it = MP_STATE_VM(ble_event_handler_entries);
    bool done = false;
    while (it != NULL) {
        // Capture next before calling the function in case it removes itself from the list.
        ble_event_handler_entry_t *next = it->next;
        done = it->func(event, it->param) || done;
        it = next;
    }
    #if CIRCUITPY_SERIAL_BLE && CIRCUITPY_VERBOSE_BLE
    ble_serial_enable();
    #endif
    return 0;
}

MP_REGISTER_ROOT_POINTER(struct ble_event_handler_entry *ble_event_handler_entries);
