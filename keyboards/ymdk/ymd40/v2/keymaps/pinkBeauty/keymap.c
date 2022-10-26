/* Copyright 2020 Boardsource
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
 * TO COMPILE, EXECUTE: qmk compile -kb ymdk/ymd40/v2 -km pinkBeauty
 *
 */

#include QMK_KEYBOARD_H
#include <sendstring_spanish.h>
//#include "rgblight.c"

enum layers {
    _QWERTY_W,
    _QWERTY_M,
    _ARROWS,
    _MOUSE,
    _SYMBOLS_W,
    _SYMBOLS_M,
    _NUMBERS,
    _LIGTHS,
    _PASSWORDS,
};

// #include "rgbmatrix.c"

// Readability keycodes
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

#define ENT_SYM LT(_SYMBOLS_M, KC_ENT)
#define BKS_SYM LT(_SYMBOLS_M, KC_BSPC)
#define BKS_SYW LT(_SYMBOLS_W, KC_BSPC)
#define ENT_NUM LT(_NUMBERS, KC_ENT)
#define F_MOU LT(_MOUSE, KC_F)
#define BKSP_MOU LT(_MOUSE, KC_BSPC)
#define SPACE_NUM LT(_NUMBERS, KC_SPC)
#define SPACE_SYM LT(_SYMBOLS_M, KC_SPC)
#define SPACE_SYW LT(_SYMBOLS_W, KC_SPC)
#define DEL_LIG LT(_LIGTHS, KC_DEL)
#define ENT_TIL LT(0,KC_ENT)

#include "custom_keycodes.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE (0)
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Tab │  Q  │  W  │  E  │  R  │  T  ││  Y  │  U  │  I  │  O  │  P  │ Bsp │
    // │AltGr│  œ  │  æ  │  €  │  ®  │  †  ││  ¥  │     │     │     │     │Comm │Crtl in win2
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Esc │  A  │  S  │  D  │  F  │  G  ││  H  │  J  │  K  │  L  │  Ñ  │  ¨  │
    // │Crtl │  å  │  ∫  │  ∂  │_MOUS│    ││  ™  │  ¶  │     │     │_NUMB│ ´ { │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Enter│  Z  │  X  │  C  │  V  │  B  ││  N  │  M  │  ;  │  :  │  _  │  Ç  │
    // │Shift│  Ω  │  ∑  │     │  √  │  ß  ││     │  µ  │  ,  │  .  │  -  │Shift│
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ RGB │ xxx │ Alt │Bcksp│Bcksp│Enter││Space│Space│Delet│ xxx │ xxx │ xxx │
    // │Toogl│_ARRO│     │_MOUS│_SYMB│Comm ││_SYMB│_SYMB│_LIGH│ xxx │ xxx │ xxx │
    // └─────┴─────┴─────┴─────┴─────┴─────┘└─────┴─────┴─────┴─────┴─────┴─────┘
   [_QWERTY_M] = LAYOUT_ortho_4x12(
    RALT_T(KC_ESC),         KC_Q,        KC_W,            KC_E,    KC_R,    KC_T,           /**/ KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,                 LGUI_T(KC_BSPC),
    LCTL_T(KC_TAB),         KC_A,        KC_S,            KC_D,    F_MOU,   KC_G,           /**/ KC_H,     KC_J,     KC_K,    KC_L,    LT(_NUMBERS,KC_SCLN), KC_QUOT /*ENT_TIL*/,
    LSFT_T(KC_ENT),         KC_Z,        KC_X,            KC_C,    KC_V,    KC_B,           /**/ KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH,              RSFT_T(KC_BSLS),
    RGB_TOG,                TG(_ARROWS), LALT_T(KC_BSPC), BKSP_MOU,BKS_SYM, LGUI_T(KC_ENT), /**/ LGUI_T(KC_ENT),SPACE_SYM,DEL_LIG, XXXXXXX, XXXXXXX,         XXXXXXX
  ),
  [_QWERTY_W] = LAYOUT_ortho_4x12(
    RALT_T(KC_ESC),         KC_Q,               KC_W,    KC_E,           KC_R,    KC_T,           /**/ KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,                 LGUI_T(KC_BSPC),
    LCTL_T(KC_TAB),         KC_A,               KC_S,    KC_D,           F_MOU,   KC_G,           /**/ KC_H,     KC_J,     KC_K,    KC_L,    LT(_NUMBERS,KC_SCLN), KC_QUOT /*ENT_TIL*/,
    LSFT_T(KC_ENT),         LT(_PASSWORDS,KC_Z),KC_X,    KC_C,           KC_V,    KC_B,           /**/ KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH,              RSFT_T(KC_BSLS),
    RGB_TOG,                TG(_ARROWS),        KC_LALT, LALT_T(KC_BSPC),BKS_SYW, LCTL_T(KC_ENT), /**/ LGUI_T(KC_ENT),SPACE_SYW,DEL_LIG, XXXXXXX, XXXXXXX,         XXXXXXX
  ),
  [_ARROWS] = LAYOUT_ortho_4x12(
    _______, S(KC_5), KC_7,    KC_8, KC_9,       KC_RBRC,    /**/ KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_VOLU, _______,
    _______, S(KC_7), KC_4,    KC_5, KC_6,       KC_SLSH,    /**/ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_PGUP,
    _______, KC_COMM, KC_1,    KC_2, KC_3,       KC_DOT,     /**/ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MUTE, KC_PGDN,
    _______, _______, _______, KC_0, S(KC_RBRC), S(KC_DOT), /**/ KC_BTN1, KC_BTN2, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
  [_PASSWORDS] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______,  /**/ _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  /**/ GSO,     WIN2,    VPN,     PER1   , PER2   , _______,
    _______, _______, _______, _______, _______, _______,  /**/ MAIL1,   MAIL2,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  /**/ _______, _______, _______, _______, _______, _______
  ),
    // Mouse LT2
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │     │     │     │     │     │     ││Mouse│Mouse│Mouse│Mouse│Vol+ │     │
    // │     │     │     │     │     │     ││W-Lef│W-Do │W-Up │W-Rig│Mmmm │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Comm │AltGr│Crtl │Shift│     │alt- ││Left │Down │ Up  │Right│Vol- │ Pg  │
    // │     │     │     │     │     │tab  ││     │     │     │     │Mmmm │ Up  │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │     │     │     │     │     ││Mouse│Mouse│Mouse│Mouse│Mute │ Pg  │
    // │     │     │     │     │     │     ││left │Down │ Up  │Right│     │Down │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ xxx │ xxx │ xxx │Butto│Butto│Butto││Butto│Butto│Butto│ xxx │ xxx │ xxx │
    // │ xxx │ xxx │ xxx │ 3   │ 2   │ 1   ││ 1   │ 2   │ 3   │ xxx │ xxx │ xxx │
    // └─────┴─────┴─────┴─────┴─────┴─────┘└─────┴─────┴─────┴─────┴─────┴─────┘
  [_MOUSE] = LAYOUT_ortho_4x12(
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      /**/ KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_VOLU, _______,
   KC_LGUI, KC_RALT, KC_LCTL, KC_LSFT, XXXXXXX, LALT(KC_TAB), /**/ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_PGUP,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      /**/ KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MUTE, KC_PGDN,
   _______, _______, _______, KC_BTN3, KC_BTN2, KC_BTN1,      /**/ KC_BTN1, KC_BTN2, KC_BTN3, _______, _______, _______
  ),
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │  <  │  >  │  ¿  │  ?  │  [  │  ]  ││  ª  │  ~  │  ^  │  ·  │ xxx │Print│
    // │     │     │     │     │     │     ││  ª  │     │     │     │ xxx │Scree│
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │  \  │  /  │  '  │  "  │  (  │  )  ││  |  │  @  │  $  │  %  │ ^   │ ¨   │
    // │     │     │     │     │     │     ││     │     │     │     │ `   │ ´   │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Enter│  *  │  ¡  │  !  │  {  │  }  ││  &  │ xxx │  ;  │  :  │  _  │  Ç  │
    // │Shift│     │     │     │     │     ││     │ xxx │  ,  │  .  │  -  │Shift│
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ xxx │ xxx │ xxx │  #  │  =  │  :  ││     │     │     │ xxx │ xxx │ xxx │
    // │ xxx │ xxx │ xxx │     │     │     ││     │     │     │ xxx │ xxx │ xxx │
    // └─────┴─────┴─────┴─────┴─────┴─────┘└─────┴─────┴─────┴─────┴─────┴─────┘
  [_SYMBOLS_M] = LAYOUT_ortho_4x12(
   KC_GRV,       S(KC_GRV), S(KC_EQL), S(KC_MINS), ALGR(KC_LBRC), ALGR(KC_RBRC), /**/  KC_NUBS,    ALGR(KC_4), S(KC_LBRC), S(KC_3), XXXXXXX,    KC_PSCR,
   ALGR(KC_NUBS),S(KC_7),   KC_MINS,   S(KC_2),    S(KC_8),       S(KC_9),       /**/  ALGR(KC_1), ALGR(KC_2), S(KC_4),    S(KC_5), KC_LBRC,    KC_QUOT,
   _______,      S(KC_RBRC),KC_EQL,    S(KC_1),    ALGR(KC_QUOT), ALGR(KC_NUHS), /**/  S(KC_6),    XXXXXXX,    _______,    _______, _______,    _______,
   _______,      _______,   _______,   ALGR(KC_3), S(KC_0),       S(KC_DOT),     /**/  S(KC_DOT),    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX
  ),
  [_SYMBOLS_W] = LAYOUT_ortho_4x12(
   KC_NUBS,     S(KC_NUBS),S(KC_EQL), S(KC_MINS), ALGR(KC_LBRC), ALGR(KC_RBRC), /**/  KC_GRV,     ALGR(KC_4), S(KC_LBRC), S(KC_3), XXXXXXX,    KC_PSCR,
   ALGR(KC_GRV),S(KC_7),   KC_MINS,   S(KC_2),    S(KC_8),       S(KC_9),       /**/  ALGR(KC_1), ALGR(KC_2), S(KC_4),    S(KC_5), KC_LBRC,    KC_QUOT,
   _______,     S(KC_RBRC),KC_EQL,    S(KC_1),    ALGR(KC_QUOT), ALGR(KC_NUHS), /**/  S(KC_6),    XXXXXXX,    _______,    _______, _______,    _______,
   XXXXXXX,     XXXXXXX,   _______,   ALGR(KC_3), S(KC_0),       S(KC_DOT),     /**/  S(KC_DOT),    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,    XXXXXXX
  ),
    // Numbers y F1-12 LT4
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Tab │     │ /   │ (   │ )   │     ││     │     │     │     │     │Bcksp│
    // │AltGr│  ,  │ 7   │ 8   │ 9   │  +  ││ F9  │ F10 │ F11 │ F12 │     │Comm │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Esc │     │ $   │ %   │ &   │  -  ││ F5  │ F6  │ F7  │ F8  │     │     │
    // │Crtl │  /  │ 4   │ 5   │ 6   │     ││     │     │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │  Ç  │     │ !   │ "   │ ·   │     ││ F1  │ F2  │ F3  │ F4  │     │     │
    // │Shift│ *   │ 1 | │ 2 @ │ 3 # │  0  ││     │     │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ xxx │ xxx │ xxx │  =  │     │     ││     │     │     │ xxx │ xxx │ xxx │
    // │ xxx │ xxx │ xxx │  0  │  .  │  :  ││     │     │     │ xxx │ xxx │ xxx │
    // └─────┴─────┴─────┴─────┴─────┴─────┘└─────┴─────┴─────┴─────┴─────┴─────┘
  [_NUMBERS] = LAYOUT_ortho_4x12(
   _______, KC_COMM,    KC_7,    KC_8, KC_9,    KC_RBRC, /**/ KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______,
   _______, S(KC_7),    KC_4,    KC_5, KC_6,    KC_SLSH, /**/ KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX,
   _______, S(KC_RBRC), KC_1,    KC_2, KC_3,    KC_0,    /**/ KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX,
   _______, _______,    _______, KC_0, KC_DOT, S(KC_DOT),  /**/ _______, _______, _______, _______, _______, _______
  ),
    // Ligths & leds LT5
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ BL  │ BL  │ BL  │RGB  │ RGB │ RGB ││ RGB │ RGB │ RGB │ RGB │ RGB │ RGB │
    // │Togle│Breat│Cycle│Togle│ P   │ B   ││ R   │ SW  │ SN  │ K   │ X   │ G   │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ BL  │ BL  │     │RGB  │ Hue │ Sat ││Brght│Effct│     │     │     │ RGB │
    // │ On  │ +   │     │Mode+│  +  │  +  ││ +   │ +   │     │     │     │ T   │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ BL  │ BL  │     │RGB  │ Hue │ Sat ││Brght│Effct│     │     │     │Reset│
    // │ Off │ -   │     │Mode-│  -  │  -  ││ -   │ -   │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ xxx │ xxx │ xxx │     │     │     ││     │     │     │ xxx │ xxx │ xxx │
    // │ xxx │ xxx │ xxx │     │     │     ││     │     │     │ xxx │ xxx │ xxx │
    // └─────┴─────┴─────┴─────┴─────┴─────┘└─────┴─────┴─────┴─────┴─────┴─────┘
  [_LIGTHS] = LAYOUT_ortho_4x12(
   BL_TOGG, BL_BRTG, BL_STEP, RGB_TOG ,     RGB_M_P,        RGB_M_B,      /**/ RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X,      RGB_M_G,
   BL_ON  , BL_INC , XXXXXXX, RGB_MOD ,      RGB_HUI,       RGB_SAI,      /**/ RGB_VAI, RGB_SPI , XXXXXXX, XXXXXXX, XXXXXXX,       RGB_M_T,
   BL_OFF , BL_DEC , XXXXXXX, RGB_RMOD,      RGB_HUD,       RGB_SAD,      /**/ RGB_VAD, RGB_SPD , XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,
   _______, _______, _______, DF(_QWERTY_W), DF(_QWERTY_M), TG(_ARROWS),  /**/ XXXXXXX, XXXXXXX,  XXXXXXX, _______, DF(_QWERTY_W), DF(_QWERTY_M)
  )
};
