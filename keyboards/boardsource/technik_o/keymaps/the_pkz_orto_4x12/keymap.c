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
 * TO COMPILE, EXECUTE: qmk compile -kb boardsource/technik_o -km the_pkz_orto_4x12
 * TO FLASH, EXECUTE: qmk flash -kb boardsource/technik_o -km the_pkz_orto_4x12
 */

#include QMK_KEYBOARD_H
//#include <sendstring_spanish.h>
#include "spanish_symbols.dtsi"
//#include "rgblight.c"
#include "rgbmatrix.c"

enum layers {
    _QWE_M,
    _QWE_W,
    _MOUSE,
    _SY1_W,
    _SY2_W,
    _SY1_M,
    _SY2_M,
    _NUMBR,
    _LIGTH,
    _PASS,
};

// Readability keycodes
#define F_MOU LT(_MOUSE, KC_F)
#define ENT_TIL LT(0,KC_ENT)
#define PSSW_X LT(_PASS,KC_X)

#include "custom_keycodes.c"
// Tap Dance declarations
enum {
    TD_TN,
};
// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_TN] = ACTION_TAP_DANCE_DOUBLE(ES_TILDE_F, ES_ENYE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWE_M] = LAYOUT_ortho_4x12(
   KC_ESC,  KC_Q,                    LGUI_T(KC_W),          LALT_T(KC_E),        LCTL_T(KC_R),        KC_T,         /**/ KC_Y,              RCTL_T(KC_U),     RALT_T(KC_I),       RGUI_T(KC_O),        KC_P,                 KC_BSPC, 
   KC_TAB,  KC_A,                    KC_S,                  KC_D,                F_MOU,               KC_G,         /**/ KC_H,              KC_J,             KC_K,               KC_L,                TD(TD_TN),            ES_TILDE_B,
   KC_LSFT, RSFT_T(KC_Z),            PSSW_X,                KC_C,                KC_V,                KC_B,         /**/ KC_N,              KC_M,             KC_COMM,            KC_DOT,              RSFT_T(ES_RESTA),     RSFT_T(ES_CEDILLA),
   RGB_TOG, XXXXXXX,                 XXXXXXX,               XXXXXXX,             LSFT_T(KC_ENT),      KC_TAB,       /**/ LT(_NUMBR,KC_BSPC),LT(_SY1_M,KC_SPC),LT(_LIGTH,KC_LEFT), KC_DOWN,             KC_UP,                KC_RGHT  
  ),                                                                                                                                                                                                                                  
  [_QWE_W] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   KC_ESC,  KC_Q,                    LGUI_T(KC_W),          LALT_T(KC_E),        LCTL_T(KC_R),        KC_T,         /**/ KC_Y,              RCTL_T(KC_U),     RALT_T(KC_I),       RGUI_T(KC_O),        KC_P,                 KC_BSPC, 
   KC_TAB,  KC_A,                    KC_S,                  KC_D,                F_MOU,               KC_G,         /**/ KC_H,              KC_J,             KC_K,               KC_L,                TD(TD_TN),            ES_TILDE_B,
   KC_LSFT, RSFT_T(KC_Z),            PSSW_X,                KC_C,                KC_V,                KC_B,         /**/ KC_N,              KC_M,             KC_COMM,            KC_DOT,              RSFT_T(KC_SLSH),      RSFT_T(ES_CEDILLA),
   RGB_TOG, XXXXXXX,                 XXXXXXX,               XXXXXXX,             LSFT_T(KC_ENT),      KC_TAB,       /**/ LT(_NUMBR,KC_BSPC),LT(_SY1_W,KC_SPC),LT(_LIGTH,KC_LEFT), KC_DOWN,             KC_UP,                KC_RGHT  
  ),                                                                                                                                                                                                                                  
  [_PASS] = LAYOUT_ortho_4x12(                                                                                                                                                                                                        
   QK_BOOT, _______,                 DF(_QWE_W),            DF(_QWE_M),          _______,             _______,      /**/ _______,           _______,           _______,           _______,             _______,              _______, 
   _______, _______,                 _______,               _______,             _______,             _______,      /**/ GSO,               WIN2,              VPN,               PER1,                PER2,                 _______, 
   _______, _______,                 _______,               _______,             _______,             _______,      /**/ MAIL1,             MAIL2,             _______,           _______,             _______,              _______, 
   _______, _______,                 _______,               _______,             _______,             _______,      /**/ _______,           _______,           _______,           _______,             _______,              _______  
  ),                                                                                                                                                                                                                                  
  [_MOUSE] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______,  XXXXXXX,                XXXXXXX,               XXXXXXX,             XXXXXXX,             XXXXXXX,      /**/ KC_WH_L,           KC_WH_U,           KC_WH_D,           KC_WH_R,              KC_VOLU,              _______,
   _______,  KC_RALT,                KC_LCTL,               KC_LSFT,             XXXXXXX,             LALT(KC_TAB), /**/ KC_LEFT,           KC_DOWN,           KC_UP  ,           KC_RGHT,              KC_VOLD,              KC_PGUP,
   _______,  KC_RGUI,                XXXXXXX,               XXXXXXX,             XXXXXXX,             XXXXXXX,      /**/ KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,              KC_MUTE,              KC_PGDN,
   _______,  _______,                _______,               XXXXXXX,             _______,             _______,      /**/ KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_DOWN,              KC_UP  ,              KC_RGHT 
  ),                                                                                                                                                                                                                                  
  [_SY1_M] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______,  KC_ESC,                 LGUI_T(ES_AND),        LALT_T(ES_INTERR_C), LGUI_T(ES_BRAQUE_A), ES_BRAQUE_C,  /**/  ES_PRIMERO_M,     KC_RCTL,           KC_RALT,           RGUI_T(ES_PUNTOALTO), LGUI(ES_MENOR_M),     _______,
   _______,  ES_FSLASH,              ES_COMILLAS_D,         ES_COMILLA_S,        ES_PARENT_A,         ES_PARENT_C,  /**/  ES_ARROBA,        ES_ALMOHAD,        ES_DOLAR,          ES_PORCENT,           ES_TILDE_F,           _______,
   _______,  LT(_SY2_M,ES_ASTERIS),  XXXXXXX,               ES_EXCLAM_C,         ES_LLAVES_A,         ES_LLAVES_C,  /**/  ES_CAPUCHON,      ES_GORRO_N_M,      ES_MENOR_M,        ES_MAYOR_M,           LT(_SY2_M,ES_CEDILLA),_______,
   _______,  _______,                _______,               _______,             LT(_SY2_M,ES_IGUAL), ES_DOSPUNT,   /**/  KC_DEL,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX 
  ),                                                                                                                                                                                                                                  
  [_SY2_M] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______,  XXXXXXX,                LGUI_T(ES_OR),         LALT_T(ES_INTERR_A), KC_LCTL,             XXXXXXX,      /**/  S(ES_PRIMERO_M),  KC_RCTL,           KC_RALT,           KC_RGUI,              ES_DIERESIS,          _______,
   _______,  ES_BSLASH_M,            XXXXXXX,               XXXXXXX,             XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              ES_TILDE_B,           _______,
   _______,  _______,                XXXXXXX,               ES_EXCLAM_A,         XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              S(ES_CEDILLA),        _______,
   _______,  _______,                _______,               _______,             XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX 
  ),                                                                                                                                                                                                                                  
  [_SY1_W] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______,  KC_ESC,                 LGUI_T(ES_AND),        LALT_T(ES_INTERR_C), LGUI_T(ES_BRAQUE_A), ES_BRAQUE_C,  /**/  ES_PRIMERO_W,     KC_RCTL,           KC_RALT,           RGUI_T(ES_PUNTOALTO), LGUI(ES_MENOR_W),     _______,
   _______,  ES_FSLASH,              ES_COMILLAS_D,         ES_COMILLA_S,        ES_PARENT_A,         ES_PARENT_C,  /**/  ES_ARROBA,        ES_ALMOHAD,        ES_DOLAR,          ES_PORCENT,           ES_TILDE_F,           _______,
   _______,  LT(_SY2_W,ES_ASTERIS),  XXXXXXX,               ES_EXCLAM_C,         ES_LLAVES_A,         ES_LLAVES_C,  /**/  ES_CAPUCHON,      ES_GORRO_N_W,      ES_MENOR_W,        ES_MAYOR_W,           LT(_SY2_W,ES_CEDILLA),_______,
   _______,  _______,                _______,               _______,             LT(_SY2_W,ES_IGUAL), ES_DOSPUNT,   /**/  KC_DEL,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX 
  ),                                                                                                                                                                                                                                  
  [_SY2_W] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______,  XXXXXXX,                LGUI_T(ES_OR),         LALT_T(ES_INTERR_A), KC_LCTL,             XXXXXXX,      /**/  S(ES_PRIMERO_W),  KC_RCTL,           KC_RALT,           KC_RGUI,              ES_DIERESIS,          _______,
   _______,  ES_BSLASH_W,            XXXXXXX,               XXXXXXX,             XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              ES_TILDE_B,           _______,
   _______,  _______,                XXXXXXX,               ES_EXCLAM_A,         XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              S(ES_CEDILLA),        _______,
   _______,  _______,                _______,               _______,             XXXXXXX,             XXXXXXX,      /**/  XXXXXXX,          XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX 
  ),                                                                                                                                                                                                                                  
  [_NUMBR] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   _______, KC_COMM,                 KC_9,                  KC_8,                KC_7,                ES_SUMA,      /**/ KC_F9,             KC_F10,            KC_F11,            KC_F12,               KC_BSPC,              _______,
   _______, ES_FSLASH,               KC_6,                  KC_5,                KC_4,                ES_RESTA,     /**/ KC_F5,             KC_F6,             KC_F7,             KC_F8,                ES_ENYE,              _______,
   _______, RSFT_T(ES_ASTERIS),      KC_3,                  KC_2,                KC_1,                KC_0,         /**/ KC_F1,             KC_F2,             KC_F3,             KC_F4,                ES_CEDILLA,           _______,
   _______, _______,                 _______,               _______,             RSFT_T(KC_DOT),      ES_DOSPUNT,   /**/ KC_BSPC,           KC_SPC,            _______,           _______,              _______,              _______ 
  ),                                                                                                                                                                                                                                  
  [_LIGTH] = LAYOUT_ortho_4x12(                                                                                                                                                                                                       
   BL_TOGG, BL_BRTG,                 BL_STEP,               RGB_TOG ,            RGB_M_P,             RGB_M_B,      /**/ RGB_M_R,           RGB_M_SW,          RGB_M_SN,          RGB_M_K,              RGB_M_X,              RGB_M_G,
   BL_ON  , BL_INC ,                 XXXXXXX,               RGB_MOD ,            RGB_HUI,             RGB_SAI,      /**/ RGB_VAI,           RGB_SPI,           XXXXXXX,           XXXXXXX,              XXXXXXX,              RGB_M_T,
   BL_OFF , BL_DEC ,                 XXXXXXX,               RGB_RMOD,            RGB_HUD,             RGB_SAD,      /**/ RGB_VAD,           RGB_SPD,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX,
   _______, _______,                 _______,               _______,             _______,             XXXXXXX,      /**/ XXXXXXX,           XXXXXXX,           XXXXXXX,           XXXXXXX,              XXXXXXX,              XXXXXXX 
  )
};
// vim:nowrap
