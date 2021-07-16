#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Jarne
#define PRODUCT         Thürn
#define DESCRIPTION     Macropad with rotary encoder and OLED screen

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* key matrix pins */
#define MATRIX_ROW_PINS { F4, F5, F6 }
#define MATRIX_COL_PINS { D4, C6, B4 }
#define UNUSED_PINS

/* rotary encoder */
#define ENCODERS_PAD_A { D7 }
#define ENCODERS_PAD_B { B5 }
#define DIP_SWITCH_PINS { B4 }
#define ENCODER_RESOLUTION 2

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

/* Oled Size */
#define OLED_DISPLAY_128X64
