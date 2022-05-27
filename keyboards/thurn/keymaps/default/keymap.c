#include "kb.h"
#include <stdio.h>

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_FIND LCTL(KC_F)
#define KC_DUPLICATE LCTL(KC_D)
#define KC_CLOSE LCTL(KC_W)
#define KC_BACK LCTL(KC_Z)
#define KC_FORWARD LCTL(KC_Y)

char wpm_str[10];

enum layer_names {
	_BASE_LAYER,
	_FIRST_LAYER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE_LAYER] = LAYOUT( 
    	KC_AUDIO_MUTE, TO(_FIRST_LAYER), 
		KC_APPLICATION, KC_MEDIA_PLAY_PAUSE, 
		KC_MPRV, KC_MNXT, KC_AUDIO_MUTE
  	),
	[_FIRST_LAYER] = LAYOUT(
    	KC_FIND, TO(_BASE_LAYER), 
		KC_DUPLICATE, KC_ENTER	, 
		KC_HOME, KC_DELETE, KC_PSCREEN //redo undo
  	)
};
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	if(IS_LAYER_ON(_BASE_LAYER)) { // on Raise layer control volume
		if (clockwise){
		tap_code(KC_VOLU);
		} else{
		tap_code(KC_VOLD);
		}     
	}   
	else if(IS_LAYER_ON(_FIRST_LAYER)){ 
		if (clockwise){
		tap_code16(KC_FORWARD);
		} else{
		tap_code16(KC_BACK);
		}
	}
	return true;
}
#endif

/*
Layer: ...
 x - x			Logo(?)Logo(?)Logo(?)
 x - x			Logo(?)Logo(?)Logo(?)
 x - x - o		Logo(?)Logo(?)Logo(?)
*/

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180; 
}
void oled_task_user(void) {
	// Host Keyboard Layer Status
	oled_write_P(PSTR("Layer: "), false);
	
	switch (get_highest_layer(layer_state)) {
		case _BASE_LAYER:
			oled_write_P(PSTR("1\n\n"), false);
			oled_write_P(PSTR("Mute - Layer\t\n" ),false);
			oled_write_P(PSTR("Wndws - Pause\t\n"),false);
			oled_write_P(PSTR("Last - Next - Mute\n"),false);
			oled_write_P(PSTR("\n"),false);
			break;
		case _FIRST_LAYER:
			oled_write_P(PSTR("2\n\n"), false);
			oled_write_P(PSTR("Find - Layer\t\n" ),false);
			oled_write_P(PSTR("Dupe - Enter\t\n"),false);
			oled_write_P(PSTR("Home - Delete - PrtSc\n"),false);
			break;
		default:
			oled_write_ln_P(PSTR("ERROR"), false);
			//Render Thürn Logo
	}
}
/*void const char Logo[] = {

};*/
#endif


/*
The simple way would be to run keymap_key_to_keycode(layer_state|default_layer_state, keypos).  Where, keypos is the column and row of a position.
my suggestion would be to have it run in the layer_state_set_(kb/user) function and dump it to an array in memory
something like this (give me a minute or three


uint16_t key_mapping[MATRIX_ROWS][MATRIX_COLs] = { 0 };
layer_state_t layer_state_set_user(layer_state_t state) {
    keypos_t keypos;
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        for (uint8_t y = 0; y < MATRIX_COLS; y++) {
             keypos = { y, x }; // col first
             key_mapping[x][y] = keymap_key_to_keycode(state|default_layer_state, keypos);
        }
    }
    return state;
}


keymap_key_to_keycode is a core function, that via basically hijacks to redirect to the eeprom
so this will work identically with or without via enabled.  so for any keymap

as for the keylogger stuff: 
https://github.com/qmk/qmk_firmware/blob/master/users/drashna/oled_stuff.c#L19-L69
You'll probably have to do a lot of adapting, but that should get you on your way :slight_smile:

-drashna#0343
*/

