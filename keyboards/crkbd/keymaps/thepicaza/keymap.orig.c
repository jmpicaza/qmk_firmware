/*
TO COMPILE, EXECUTE: qmk compile -kb crkbd/rev1 -km thepicaza

*/

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"
#include <stdio.h>
// #include "action_layer.h"
#include "rgblight.c"
#include "rgbmatrix.c"


#define ALTGR_Z RALT_T(KC_Z)
#define ALT_X LALT_T(KC_X)
#define CRTL_C LCTL_T(KC_C)
#define SHIFT_V LSFT_T(KC_V)
#define MAC_B LGUI_T(KC_B)

#define MAC_N LGUI_T(KC_N)
#define SHIFT_M LSFT_T(KC_M)
#define CRTL_COMM LCTL_T(KC_COMM)
#define ALT_DOT LALT_T(KC_DOT)
#define ALTGR_SLSH LGUI_T(KC_SLSH)

#define ESC_L3 LT(3,KC_ESC)
#define BSPC_L1 LT(1,KC_BSPC)
#define ENTER_L2 LT(2,KC_ENT)
#define TAB_L4 LT(4,KC_TAB)
#define SPACE_L3 LT(3,KC_SPC)
#define DEL_L5 LT(5,KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // BASE (0)
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Tab │  Q  │  W  │  E  │  R  │  T  │      │  Y  │  U  │  I  │  O  │  P  │ Bsp │
    // │     │     │     │     │     │     │      │     │     │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ Esc │  A  │  S  │  D  │  F  │  G  │      │  H  │  J  │  K  │  L  │  Ñ  │     │
    // │     │     │     │     │     │     │      │     │     │     │     │     │  ´ {│
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ >   │  Z  │  X  │  C  │  V  │  B  │      │  N  │  M  │  ,  │  .  │  -  │  Ç  │
    // │ <   │AltGr│ Alt │Crtl │Shift│Comm │      │Comm │Shift│Crtl │ Alt │AltGr│     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //           ┌───────┐                                         ┌───────┐
    //           │ LT3   |                                         | LT5   │
    //           │ Esc   ├─────────┐                      ┌────────┤Delete │
    //           └───────┤ LT1     ├─────────┐  ┌─────────┤ LT3    ├───────┘
    //                   |BackSpace| LT2     |  | LT4     | Space  |
    //                   └─────────┤ Enter   │  │ Tab     ├────────┘
    //                             └─────────┘  └─────────┘
	[0] = LAYOUT_split_3x6_3(
        KC_TAB , KC_Q   , KC_W , KC_E  , KC_R   , KC_T ,      KC_Y , KC_U   , KC_I     , KC_O   , KC_P      , KC_BSPC,
        KC_ESC , KC_A   , KC_S , KC_D  , KC_F   , KC_G ,      KC_H , KC_J   , KC_K     , KC_L   , KC_SCLN   , KC_QUOT,
        KC_COMM, ALTGR_Z, ALT_X, CRTL_C, SHIFT_V, MAC_B,      MAC_N, SHIFT_M, CRTL_COMM, ALT_DOT, ALTGR_SLSH, KC_BSLS,
                                 ESC_L3, BSPC_L1, ENTER_L2,      TAB_L4, SPACE_L3, DEL_L5
    ),
    // Navegacion LT1
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Tab │     │     │     │     │     │      │Copy │Mouse│Mouse│Paste│Cut  │ Bsp │
    // │     │     │     │     │     │     │      │     │W-Do │W-Up │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Caps │     │     │     │     │     │      │Left │Down │ Up  │Right│     │     │
    // │Lock │     │     │     │     │     │      │     │     │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Reset│     │     │     │     │     │      │ Bsp │Page │Page │     │     │     │
    // │     │AltGr│ Alt │Crtl │Shift│Comm │      │     │Down │ Up  │     │     │     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //           ┌───────┐                                         ┌───────┐
    //           │       |                                         |       │
    //           │       ├─────────┐                      ┌────────┤BackSpa│
    //           └───────┤ x LT1 x ├─────────┐  ┌─────────┤        ├───────┘
    //                   | xxxxxxx |         |  |         | Space  |
    //                   └─────────┤         │  │ Tab     ├────────┘
    //                             └─────────┘  └─────────┘
	[1] = LAYOUT_split_3x6_3(
        KC_TAB , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_COPY, KC_WH_D, KC_WH_U, KC_PSTE, KC_CUT, KC_BSPC,
        KC_CAPS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO , KC_NO  ,
        RESET  , KC_RALT, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_BSPC, KC_PGDN, KC_PGUP, KC_NO  , KC_NO , KC_NO  ,
                                   KC_NO  , KC_NO  , KC_NO  ,    KC_TAB , KC_SPC , KC_BSPC
    ),
    // Mouse LT2
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ Tab │Print│     │     │     │     │      │Mouse│Mouse│Mouse│Mouse│Vol+ │     │
    // │     │Scree│     │     │     │     │      │W-Lef│W-Do │W-Up │W-Rig│Mmmm │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │     │     │     │     │     │      │Left │Down │ Up  │Right│Vol- │     │
    // │ Esc │     │     │     │     │     │      │     │     │     │     │Mmmm │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Reset│     │     │     │     │     │      │Mouse│Mouse│Mouse│Mouse│Mute │     │
    // │     │AltGr│ Alt │Crtl │Shift│Comm │      │left │Down │ Up  │Right│     │     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //           ┌───────┐                                         ┌───────┐
    //           │       |                                         | Mouse │
    //           │       ├─────────┐                      ┌────────┤ But-3 │
    //           └───────┤         ├─────────┐  ┌─────────┤ Mouse  ├───────┘
    //                   |         | x LT2 x |  | Mouse   | But-2  |
    //                   └─────────┤ xxxxxxx │  │ But-1   ├────────┘
    //                             └─────────┘  └─────────┘
	[2] = LAYOUT_split_3x6_3(
        KC_TAB, KC_PSCR, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_VOLU, KC_NO,
        KC_ESC, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_VOLD, KC_NO,
        RESET , KC_RALT, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MUTE, KC_NO,
                                  KC_NO  , KC_NO  , KC_NO  ,    KC_BTN1, KC_BTN2, KC_BTN3
    ),
    // Programming LT3
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │  ¿  │  ?  │  ~  │  %  │  [  │  ]  │      │  <  │  >  │  @  │  |  │Print│     │
    // │     │     │     │     │     │     │      │     │     │     │     │Sc < │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │  ¡  │  !  │  '  │  "  │  (  │  )  │      │  \  │  /  │ $   │ ª   │ `   │ ´   │
    // │     │     │     │     │     │     │      │     │     │     │ º   │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │  ^  │  &  │  +  │  *  │  {  │  }  │      │     │     │     │     │     │Reset│
    // │     │     │     │     │     │     │      │Comm │Shift│Crtl │ Alt │AltGr│     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //          ┌────────┐                                         ┌───────┐
    //          │        |                                         |       │
    //          │   #    ├─────────┐                      ┌────────┤       │
    //          └────────┤         ├─────────┐  ┌─────────┤ x LT3 x├───────┘
    //                   |    =    |         |  |         | xxxxxxx|
    //                   └─────────┤    :    │  │         ├────────┘
    //                             └─────────┘  └─────────┘
	[3] = LAYOUT_split_3x6_3(
        S(KC_EQL) , S(KC_MINS), ALGR(KC_SCLN), S(KC_5)    , ALGR(KC_LBRC), ALGR(KC_RBRC),      KC_GRV       , S(KC_GRV), ALGR(KC_2), ALGR(KC_1), G(KC_GRV), KC_NO  ,
        KC_EQL    , S(KC_1)   , KC_MINS       , S(KC_2)   , S(KC_8)      , S(KC_9)      ,      ALGR(KC_NUBS), S(KC_7)  , S(KC_4)   , KC_NUBS   , KC_LBRC  , KC_QUOT,
        S(KC_LBRC), S(KC_6)   , KC_RBRC       , S(KC_RBRC), ALGR(KC_QUOT), ALGR(KC_NUHS),      KC_LGUI      , KC_LSFT  , KC_LCTL   , KC_LALT   , KC_RALT  , RESET  ,
                                                ALGR(KC_3), S(KC_0)      , S(KC_DOT)    ,      KC_NO        , KC_NO    , KC_NO
    ),
    // Numbers y F1-12 LT4    
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │     │     │ /   │ (   │ )   │     │      │     │     │     │     │     │     │
    // │     │     │ 7   │ 8   │ 9   │     │      │ F9  │ F10 │ F11 │ F12 │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │     │     │ $   │ %   │ &   │     │      │ F5  │ F6  │ F7  │ F8  │     │     │
    // │     │     │ 4   │ 5   │ 6   │     │      │     │     │     │     │     │     │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │Print│ ;   │ !   │ "   │ ·   │ :   │      │ F1  │ F2  │ F3  │ F4  │     │     │
    // │Scree│ ,   │ 1 | │ 2 @ │ 3 # │ .   │      │Comm │Shift│Crtl │ Alt │AltGr│     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //          ┌────────┐                                         ┌───────┐
    //          │  =     |                                         |       │
    //          │  0     ├─────────┐                      ┌────────┤       │
    //          └────────┤         ├─────────┐  ┌─────────┤        ├───────┘
    //                   |         |         |  | x LT4 x |        |
    //                   └─────────┤         │  │ xxxxxxx ├────────┘
    //                             └─────────┘  └─────────┘
	[4] = LAYOUT_split_3x6_3(
        KC_NO  , KC_NO  , KC_7, KC_8, KC_9 , KC_NO ,    KC_F11       , KC_F12       , KC_NO        , KC_NO        , KC_NO        , KC_NO,
        KC_NO  , KC_NO  , KC_4, KC_5, KC_6 , KC_NO ,    KC_F6        , KC_F7        , KC_F8        , KC_F9        , KC_F10       , KC_NO,
        KC_PSCR, KC_COMM, KC_1, KC_2, KC_3 , KC_DOT,    LGUI_T(KC_F1), LSFT_T(KC_F2), LCTL_T(KC_F3), LALT_T(KC_F4), RALT_T(KC_F5), KC_NO,
                                KC_0, KC_NO, KC_NO ,    KC_NO        , KC_NO        , KC_NO
    ),
    // Ligths & leds LT5
    // ┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
    // │ BL  │ BL  │ BL  │RGB  │ RGB │ RGB │      │ RGB │ RGB │ RGB │ RGB │ RGB │ RGB │
    // │Togle│Breat│Cycle│Togle│ P   │ B   │      │ R   │ SW  │ SN  │ K   │ X   │ G   │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ BL  │ BL  │     │RGB  │ Hue │ Sat │      │Brght│Effct│     │     │     │ RGB │
    // │ On  │ +   │     │Mode+│  +  │  +  │      │ +   │ +   │     │     │     │ T   │
    // ├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
    // │ BL  │ BL  │     │RGB  │ Hue │ Sat │      │Brght│Effct│     │     │     │Reset│
    // │ Off │ -   │     │Mode-│  -  │  -  │      │ -   │ -   │     │     │     │     │
    // └─────┴─────┴─────┴─────┴─────┴─────┘      └─────┴─────┴─────┴─────┴─────┴─────┘
    //          ┌────────┐                                         ┌───────┐
    //          │        |                                         |x LT5 x│
    //          │        ├─────────┐                      ┌────────┤xxxxxxx│
    //          └────────┤         ├─────────┐  ┌─────────┤        ├───────┘
    //                   |         |         |  |         |        |
    //                   └─────────┤         │  │         ├────────┘
    //                             └─────────┘  └─────────┘
	[5] = LAYOUT_split_3x6_3(
        BL_TOGG, BL_BRTG, BL_STEP, RGB_TOG , RGB_M_P, RGB_M_B,    RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G,
        BL_ON  , BL_INC , KC_NO  , RGB_MOD , RGB_HUI, RGB_SAI,    RGB_VAI, RGB_SPI , KC_NO   , KC_NO  , KC_NO  , RGB_M_T,
        BL_OFF , BL_DEC , KC_NO  , RGB_RMOD, RGB_HUD, RGB_SAD,    RGB_VAD, RGB_SPD , KC_NO   , KC_NO  , KC_NO  , RESET  ,
                                   KC_NO   , KC_NO  , KC_NO  ,    KC_NO  , KC_NO   , KC_NO
    )
};

// OLED
// ////

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_NAVIGATION 2
#define L_MOUSE 4
#define L_SYMBOLS 8
#define L_NUMBERS 16
#define L_LIGTHS 32

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("QUERTY"), false);
            break;
        case L_NAVIGATION:
            oled_write_ln_P(PSTR("Cursor"), false);
            break;
        case 
            L_MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case 
            L_SYMBOLS:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case 
            L_NUMBERS:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case 
            L_LIGTHS:
            oled_write_ln_P(PSTR("RGB Ligths"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
