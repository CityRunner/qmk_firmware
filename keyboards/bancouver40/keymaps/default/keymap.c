/*
Copyright 2022 CityRunner

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

/* Colemak home row mods */
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define CTR_S LCTL_T(KC_S)
#define SHF_T LSFT_T(KC_T)

#define SHF_N RSFT_T(KC_N)
#define CTR_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

/* QWERTY home row mods*/
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTR_D LCTL_T(KC_D)
#define SHF_F LSFT_T(KC_F)

#define SHF_J    RSFT_T(KC_J)
#define CTR_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

/* Bottom row mods */
#define NUM_SPC LT(_NUMERIC,    KC_SPACE)
#define SYM_ESC LT(_SYMBOLIC,   KC_ESCAPE)
#define FUN_ENT LT(_FUNCTION,   KC_ENTER)
#define NAV_BSP LT(_NAVIGATION, KC_BACKSPACE)
#define SYS_NUL MO(_SYSTEM)

/* Layout switching */
#define LAY_COL DF(_COLEMAK)
#define LAY_QWE DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-------------------------------------------------------------------------------.
 * |   q   |   w   |   f   |   p   |   b   |   j   |   l   |   u   |   y   |  ; :  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | a-gui | r-alt |s-ctrl |t-shift|   g   |   m   |n-shift|e-ctrl | i-alt | o-gui |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   z   |   x   |   c   |   d   |   v   |   k   |   h   |  , <  |  . >  |  / ?  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |system | menu  |  tab  |spc-num|esc-sym|ent-fun|bsp-nav|  del  | vol-  | vol+  |
 * `-------------------------------------------------------------------------------'
 */
  [_COLEMAK] = LAYOUT_ortho_4x10(
    KC_Q,    KC_W,   KC_F,   KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    GUI_A,   ALT_R,  CTR_S,  SHF_T,   KC_G,    KC_M,    SHF_N,   CTR_E,   ALT_I,   GUI_O,
    KC_Z,    KC_X,   KC_C,   KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
    SYS_NUL, KC_APP, KC_TAB, NUM_SPC, SYM_ESC, FUN_ENT, NAV_BSP, KC_DEL,  KC_VOLD, KC_VOLU
    ),

/* QWERTY
 * ,-------------------------------------------------------------------------------.
 * |   q   |   w   |   e   |   r   |   t   |   y   |   y   |   i   |   o   |   p   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | a-gui | s-alt |d-ctrl |f-shift|   g   |   h   |j-shift|k-ctrl | l-alt | ;-gui |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   z   |   x   |   c   |   v   |   b   |   n   |   m   |  , <  |  . >  |  / ?  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |system | menu  |  tab  |spc-num|esc-sym|ent-fun|bsp-nav|  del  | vol-  | vol+  |
 * `-------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_4x10(
    KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    GUI_A,   ALT_S,  CTR_D,  SHF_F,   KC_G,    KC_H,    SHF_J,   CTR_K,   ALT_L,   GUI_SCLN,
    KC_Z,    KC_X,   KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    SYS_NUL, KC_APP, KC_TAB, NUM_SPC, SYM_ESC, FUN_ENT, NAV_BSP, KC_DEL,  KC_VOLD, KC_VOLU
    ),

/* Numeric
 * ,-------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |  7 &  |  8 *  |  9 (  |  0 )  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  4 $  |  5 %  |  6 ^  |  - _  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  1 !  |  2 @  |  3 $  |  = +  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * `-------------------------------------------------------------------------------'
 */
  [_NUMERIC] = LAYOUT_ortho_4x10(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_MINUS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_EQUAL,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Symbolic
 * ,-------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |  [ {  |  ] }  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |  ` ~  |  ' "  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |  \ |  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * `-------------------------------------------------------------------------------'
 */
  [_SYMBOLIC] = LAYOUT_ortho_4x10(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_QUOT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Function
 * ,-------------------------------------------------------------------------------.
 * |  F1   |  F2   |  F3   |  F4   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F5   |  F6   |  F7   |  F8   |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F9   |  F10  |  F11  |  F12  |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * `-------------------------------------------------------------------------------'
 */
  [_FUNCTION] = LAYOUT_ortho_4x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Navigation
 * ,-------------------------------------------------------------------------------.
 * | home  |  end  |page up|page dn|       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  up   | down  | left  | right |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * `-------------------------------------------------------------------------------'
 */
  [_NAVIGATION] = LAYOUT_ortho_4x10(
    KC_HOME, KC_END,  KC_PGUP, KC_PGDN,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_UP  , KC_DOWN, KC_LEFT, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* System
 * ,-------------------------------------------------------------------------------.
 * |spleep |       |       |       |       |       |       |       |       | pause |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | caps  |       |       |       |       |       |       |       |       |insert |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |Colemak|QWERTY |       |       |       |       |       |bright-|bright+|
 * `-------------------------------------------------------------------------------'
 */
  [_SYSTEM] = LAYOUT_ortho_4x10(
    KC_SLEP, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_PAUSE,
    KC_CAPS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_INS,
    CG_TOGG, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
    KC_TRNS, LAY_COL, LAY_QWE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU
    )

};

enum combos {
  /* [vol-] and [vol+] for [mute] */
  VOL_MUTE,
  /* [y] and [;] for [prt scrn] */
  COL_PRNT,
};

const uint16_t PROGMEM mute_combo[] = {KC_VOLD, KC_VOLU, COMBO_END};
const uint16_t PROGMEM prnt_combo[] = {KC_Y,    KC_SCLN, COMBO_END};

combo_t key_combos[] = {
  [VOL_MUTE] = COMBO(mute_combo, KC_MUTE),
  [COL_PRNT] = COMBO(prnt_combo, KC_PSCR)
};
