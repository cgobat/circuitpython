/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Glenn Ruben Bakke
 * Copyright (c) 2018 Dan Halbert for Adafruit Industries
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

#include "nrfx/hal/nrf_gpio.h"

#define MICROPY_HW_BOARD_NAME       "micro:bit v1"
#define MICROPY_HW_MCU_NAME         "nRF51822"

#define CIRCUITPY_INTERNAL_NVM_SIZE 0
#define CIRCUITPY_INTERNAL_FLASH_FILESYSTEM_SIZE (30 * 1024)

#define CIRCUITPY_BLE_CONFIG_SIZE       (12 * 1024)

// Reduce nRF SoftRadio memory usage
#define BLEIO_VS_UUID_COUNT 10
#define BLEIO_HVN_TX_QUEUE_SIZE 2
#define BLEIO_CENTRAL_ROLE_COUNT 2
#define BLEIO_PERIPH_ROLE_COUNT 2
#define BLEIO_TOTAL_CONNECTION_COUNT 2
#define BLEIO_ATTR_TAB_SIZE (BLE_GATTS_ATTR_TAB_SIZE_DEFAULT * 2)

#define SOFTDEVICE_RAM_SIZE (16 * 1024)

#define BOOTLOADER_SIZE (0)
#define BOOTLOADER_SETTING_SIZE (0)

#define BOARD_HAS_32KHZ_XTAL (0)

#define DEFAULT_I2C_BUS_SCL     (&pin_P0_00)
#define DEFAULT_I2C_BUS_SDA     (&pin_P0_30)

#define DEFAULT_SPI_BUS_MOSI    (&pin_P0_21)
#define DEFAULT_SPI_BUS_MISO    (&pin_P0_22)
#define DEFAULT_SPI_BUS_SCK     (&pin_P0_23)

#define CIRCUITPY_CONSOLE_UART_TX (&pin_P0_24)
#define CIRCUITPY_CONSOLE_UART_RX (&pin_P0_25)
