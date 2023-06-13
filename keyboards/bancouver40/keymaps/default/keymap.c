/*
Copyright 2022 cityrunner

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum bancouver40_layers {
  _COLEMAK,
  _QWERTY,
  _NUMERIC,
  _SYMBOLIC,
  _FUNCTION,
  _NAVIGATION,
  _SYSTEM
};

/* Left-hand home row mods for QWERTY */
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)

/* Right-hand home row mods for QWERTY */
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

/* Left-hand home row mods for Colemak */
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTL_T LCTL_T(KC_T)

/* Right-hand home row mods for Colemak */
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

/* Bottom-row mods */
#define NUM_SPC LT(_NUMERIC,    KC_SPACE)
#define SYM_ESC LT(_SYMBOLIC,   KC_ESCAPE)
#define FUN_ENT LT(_FUNCTION,   KC_ENTER)
#define NAV_BSP LT(_NAVIGATION, KC_BSPACE)
#define SYS_NUL MO(_SYSTEM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_ortho_4x10(
    KC_Q,    KC_W,   KC_F,   KC_P,    KC_B,    KC_J,    KC_L,    KC_U,      KC_Y,    KC_SCLN,
    GUI_A,   ALT_R,  SFT_S,  CTL_T,   KC_G,    KC_M,    CTL_N,   SFT_E,     ALT_I,   GUI_O,
    KC_Z,    KC_X,   KC_C,   KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM,   KC_DOT,  KC_SLSH,
    SYS_NUL, KC_APP, KC_TAB, NUM_SPC, SYM_ESC, FUN_ENT, NAV_BSP, KC_DELETE, KC_VOLD, KC_VOLU
    ),

  [_QWERTY] = LAYOUT_ortho_4x10(
    KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,
    GUI_A,   ALT_S,  SFT_D,  CTL_F,   KC_G,    KC_H,    CTL_J,   SFT_K,     ALT_L,   GUI_SCLN,
    KC_Z,    KC_X,   KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_SLSH,
    SYS_NUL, KC_APP, KC_TAB, NUM_SPC, SYM_ESC, FUN_ENT, NAV_BSP, KC_DELETE, KC_VOLD, KC_VOLU
    ),

  [_NUMERIC] = LAYOUT_ortho_4x10(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_MINUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_EQUAL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

  [_SYMBOLIC] = LAYOUT_ortho_4x10(
    KC_NO,     KC_NO,    KC_NO,    KC_NO,       KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
    KC_GRAVE,  KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOTE,
    KC_BSLASH, KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_BSLASH,
    KC_NO,     KC_NO,    KC_NO,    KC_NO,       KC_NO,       MO(3),   KC_NO,   KC_NO,   KC_NO,    KC_NO
    ),

  [_FUNCTION] = LAYOUT_ortho_4x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

  [_NAVIGATION] = LAYOUT_ortho_4x10(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_UP  , KC_DOWN, KC_LEFT, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

  [_SYSTEM] = LAYOUT_ortho_4x10(
    QK_REBOOT, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,     KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,     KC_NO, KC_NO, MAGIC_SWAP_LCTL_LGUI,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO,     KC_NO, KC_NO, MAGIC_UNSWAP_LCTL_LGUI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )

};