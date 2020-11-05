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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,           KC_INS,
                 KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGDN,
                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,
        KC_SPC,  M(4),    KC_LCTL,                            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______,          _______,
                 _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, _______,
        _______, _______, _______, _______, KC_COLN, KC_DQUO, _______,          _______,
                 _______, _______, KC_LABK, KC_RABK, KC_QUES, _______, _______,
        _______, _______, _______,                            _______, _______, _______
    ),
    [2] = LAYOUT(
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______,          _______,
                 KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_3,    _______, _______, _______,          _______,
                 _______, KC_0,    _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______, _______, _______
    ),

};
