/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Dan Halbert for Adafruit Industries
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

#include "py/runtime.h"

#include "shared-bindings/util.h"

// If so, deinit() has already been called on the object, so complain.
void raise_deinited_error(void) {
    mp_raise_ValueError(translate("Object has been deinitialized and can no longer be used. Create a new object."));
}

void properties_print_helper(const mp_print_t *print, mp_obj_t self_in, const mp_arg_t *properties, size_t n_properties) {
    const mp_obj_type_t *type = mp_obj_get_type(self_in);
    mp_printf(print, "%q(", type->name);
    for (size_t i = 0; i < n_properties; i++) {
        if (i > 0) {
            mp_print_str(print, ", ");
        }
        mp_printf(print, "%q=", properties[i].qst);
        mp_obj_print_helper(print, mp_load_attr(self_in, properties[i].qst), PRINT_REPR);
    }
    mp_print_str(print, ")");
}

void properties_construct_helper(mp_obj_t self_in, const mp_arg_t *args, const mp_arg_val_t *vals, size_t n_properties) {
    for (size_t i = 0; i < n_properties; i++) {
        if (vals[i].u_obj != NULL) {
            mp_store_attr(self_in, args[i].qst, vals[i].u_obj);
        }
    }
}
