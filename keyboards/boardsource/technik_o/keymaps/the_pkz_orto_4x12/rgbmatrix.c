#ifdef RGB_MATRIX_ENABLE
// Sets the default values for the RGB LEDs.
uint8_t prev = _QWE_M;
uint32_t desiredmode = 33;
uint16_t hue = 120;
uint16_t sat = 255;
uint16_t val = 250;

// Does something to grab the RGB LED values to retain when switching layers.
void get_hsv(void) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
}
void reset_hsv(void) {
    rgblight_sethsv(hue, sat, val);
}
void matrix_init_user() {
    rgblight_mode(desiredmode);
    rgblight_enable();
    reset_hsv();
}
// Section to change RGB LED colours and animation when activating layer 1 and 2, and then go back to the default, which I can change on the fly.
  uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  if (prev!=_LIGTH) {
      switch (layer) {
        case _QWE_M:
          rgblight_mode_noeeprom(desiredmode);
          reset_hsv();
          break;
        case _QWE_W:
          rgblight_mode_noeeprom(desiredmode);
          reset_hsv();
          break;
        case _MOUSE:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_BLUE);
          break;
        case _SY1_M:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_ORANGE);
          break;
        case _SY1_W:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_ORANGE);
          break;
        case _NUMBR:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_GREEN);
          break;  
        case _LIGTH:
          rgblight_mode_noeeprom(desiredmode);
          reset_hsv();
          break;
      }
  } else {
      desiredmode = rgblight_get_mode();
      get_hsv();
  }
  prev = layer;
  return state;
}
#endif
