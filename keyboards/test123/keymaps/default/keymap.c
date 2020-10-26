/* Copyright 2020 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
//#include QMK_KEYBOARD_H
//
//const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    [0] = LAYOUT(
//        KC_BRIU, KC_BRID, KC_PSCR,
//        BL_ON,  BL_OFF,  BL_BRTG,
//        BL_INC,    BL_DEC,    KC_9,
//        KC_A,    KC_SLCK, KC_PAUS
//    ),
//    [1] = LAYOUT(
//        _______, _______, RESET,
//        _______, _______, _______,
//        _______, _______, _______,
//        _______, _______, _______
//    ),
//
//};

#include QMK_KEYBOARD_H
#include "analog.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR
};
//int foo(void) {
//    if (analogRead(F0)>50) {
//        SEND_STRING("QMK is the best thing ever!");
//    } else {
//        return -1;
//    }
//}
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_BRIU, KC_BRID, KC_PSCR,
        KC_BRID,  BL_OFF,  BL_BRTG,
        BL_INC, BL_DEC,    KC_9,
        KC_A,    KC_B, KC_C
    ),
    [1] = LAYOUT(
        _______, _______, RESET,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______
    ),

};

// custom 
unsigned int ADC0_value = 0;
unsigned int last_ADC0_value = 0;
unsigned int current_BRI = 0; 


void matrix_init_user(void) 
{
	ADC0_value = analogReadPin(F7);
	current_BRI = (ADC0_value/100)*100;
}

void matrix_scan_user(void) 
{
	char str[5];
	ADC0_value = analogReadPin(F7);

	if (ADC0_value >= (current_BRI + 100))
	{
		current_BRI = current_BRI+100;
		tap_code(KC_BRIU);
		itoa(current_BRI, str, 10);
		send_string(str);
		send_string("\n");
	}
	else if (ADC0_value <= (current_BRI - 100))
	{
			if(current_BRI > 0)
			{
				current_BRI = current_BRI-100;
				tap_code(KC_BRID);
				itoa(current_BRI, str, 10);
				send_string(str);
				send_string("\n");
			}
	}
}
