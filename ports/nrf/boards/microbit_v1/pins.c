#include "shared-bindings/board/__init__.h"

STATIC const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    { MP_ROM_QSTR(MP_QSTR_P0), MP_ROM_PTR(&pin_P0_03) }, // RING0 (PAD1)
    { MP_ROM_QSTR(MP_QSTR_P1), MP_ROM_PTR(&pin_P0_02) }, // RING1 (PAD2)
    { MP_ROM_QSTR(MP_QSTR_P2), MP_ROM_PTR(&pin_P0_01) }, // RING2 (PAD3)
    { MP_ROM_QSTR(MP_QSTR_P3), MP_ROM_PTR(&pin_P0_04) }, // COL1R
    { MP_ROM_QSTR(MP_QSTR_P4), MP_ROM_PTR(&pin_P0_05) }, // COL2R
    { MP_ROM_QSTR(MP_QSTR_P5), MP_ROM_PTR(&pin_P0_17) }, // BTN A
    { MP_ROM_QSTR(MP_QSTR_BTN_A), MP_ROM_PTR(&pin_P0_17) },
    { MP_ROM_QSTR(MP_QSTR_P6), MP_ROM_PTR(&pin_P0_12) }, // COL9R
    { MP_ROM_QSTR(MP_QSTR_P7), MP_ROM_PTR(&pin_P0_11) }, // COL8R
    { MP_ROM_QSTR(MP_QSTR_P8), MP_ROM_PTR(&pin_P0_18) }, // GPIO
    { MP_ROM_QSTR(MP_QSTR_P9), MP_ROM_PTR(&pin_P0_10) }, // COL7R
    { MP_ROM_QSTR(MP_QSTR_P10), MP_ROM_PTR(&pin_P0_06) }, // COL3R
    { MP_ROM_QSTR(MP_QSTR_P11), MP_ROM_PTR(&pin_P0_26) }, // BTN B
    { MP_ROM_QSTR(MP_QSTR_BTN_B), MP_ROM_PTR(&pin_P0_26) },
    { MP_ROM_QSTR(MP_QSTR_P12), MP_ROM_PTR(&pin_P0_20) }, // GPIO
    { MP_ROM_QSTR(MP_QSTR_P13), MP_ROM_PTR(&pin_P0_23) }, // SPI SCK
    { MP_ROM_QSTR(MP_QSTR_SCK), MP_ROM_PTR(&pin_P0_23) },
    { MP_ROM_QSTR(MP_QSTR_P14), MP_ROM_PTR(&pin_P0_22) }, // MISO
    { MP_ROM_QSTR(MP_QSTR_MISO), MP_ROM_PTR(&pin_P0_22) }
    { MP_ROM_QSTR(MP_QSTR_P15), MP_ROM_PTR(&pin_P0_21) }, // MOSI
    { MP_ROM_QSTR(MP_QSTR_MOSI), MP_ROM_PTR(&pin_P0_21) },
    { MP_ROM_QSTR(MP_QSTR_P16), MP_ROM_PTR(&pin_P0_16) }, // GPIO

    { MP_ROM_QSTR(MP_QSTR_P19), MP_ROM_PTR(&pin_P0_00) }, // I2C SCL
    { MP_ROM_QSTR(MP_QSTR_SCL), MP_ROM_PTR(&pin_P0_00) },
    { MP_ROM_QSTR(MP_QSTR_P20), MP_ROM_PTR(&pin_P0_30) }, // I2C SDA
    { MP_ROM_QSTR(MP_QSTR_SDA), MP_ROM_PTR(&pin_P0_30) },

    { MP_ROM_QSTR(MP_QSTR_RESET), MP_ROM_PTR(&pin_P0_19) }, // TGT_NRESET
    
    { MP_ROM_QSTR(MP_QSTR_RX), MP_ROM_PTR(&pin_P0_25) }, // TGT_RX
    { MP_ROM_QSTR(MP_QSTR_TX), MP_ROM_PTR(&pin_P0_24) }, // TGT_TX

    { MP_ROM_QSTR(MP_QSTR_COL1), MP_ROM_PTR(&pin_P0_04) }, // aka P3
    { MP_ROM_QSTR(MP_QSTR_COL2), MP_ROM_PTR(&pin_P0_05) }, // aka P4
    { MP_ROM_QSTR(MP_QSTR_COL3), MP_ROM_PTR(&pin_P0_06) }, // aka P10
    { MP_ROM_QSTR(MP_QSTR_COL4), MP_ROM_PTR(&pin_P0_07) },
    { MP_ROM_QSTR(MP_QSTR_COL5), MP_ROM_PTR(&pin_P0_08) },
    { MP_ROM_QSTR(MP_QSTR_COL6), MP_ROM_PTR(&pin_P0_09) },
    { MP_ROM_QSTR(MP_QSTR_COL7), MP_ROM_PTR(&pin_P0_10) }, // aka P9
    { MP_ROM_QSTR(MP_QSTR_COL8), MP_ROM_PTR(&pin_P0_11) }, // aka P7
    { MP_ROM_QSTR(MP_QSTR_COL9), MP_ROM_PTR(&pin_P0_12) }, // aka P6

    { MP_ROM_QSTR(MP_QSTR_ROW1), MP_ROM_PTR(&pin_P0_15) },
    { MP_ROM_QSTR(MP_QSTR_ROW2), MP_ROM_PTR(&pin_P0_14) },
    { MP_ROM_QSTR(MP_QSTR_ROW3), MP_ROM_PTR(&pin_P0_13) },

    { MP_ROM_QSTR(MP_QSTR_COMPASS_INT1), MP_ROM_PTR(&pin_P0_29) },
    { MP_ROM_QSTR(MP_QSTR_ACCEL_INT1), MP_ROM_PTR(&pin_P0_28) },
    { MP_ROM_QSTR(MP_QSTR_ACCEL_INT2), MP_ROM_PTR(&pin_P0_27) },
};

MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
