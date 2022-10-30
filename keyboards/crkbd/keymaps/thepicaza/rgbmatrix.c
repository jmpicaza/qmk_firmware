#ifdef RGB_MATRIX_ENABLE
    /*

      .-----------------------------------------------------------.
      |   24    |   23    |   18    |   17    |    10   |    9    |
      |---------+--------[2]--------+--------[1]-------[0]--------|
      |   25    |   22    |   19    |   16    |    11   |    8    |
      |---------+--------[3]--------+---------+---------+---------|
      |   26    |   21    |   20    |   15    |    12   |    7    |
      `---------+---------+---------+--------[4]-------[5]--------+---------.
                                               \   14   |   13    |    6    |
                                               `---------------------------´
    */
/*    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            switch(get_highest_layer(layer_state|default_layer_state)) {
                case _MOUSE: rgb_matrix_set_color(i, HSV_GREEN); break;
                case _SYMBOLS: rgb_matrix_set_color(i, RGB_ORANGE); break;
                case _NUMBERS: rgb_matrix_set_color(i, HSV_PURPLE); break;
                case _LIGTHS: rgb_matrix_set_color(i, HSV_PURPLE); break;
                default:
                    break;
            }
        }
        }
*/
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
uint32_t layer_state_set_user(uint32_t state) 
{
  uint8_t layer = biton32(state);
  if (prev!=_LIGTH) {
      switch (layer) {
        case _QWE_W:
          rgblight_mode_noeeprom(desiredmode);
          reset_hsv();
          break;
        case _QWE_M:
          rgblight_mode_noeeprom(desiredmode);
          reset_hsv();
          break;
        case _MOUSE:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_BLUE);
          break;
        case _SY1_W:
          rgblight_mode_noeeprom(0);
          rgblight_sethsv(HSV_ORANGE);
          break;
        case _SY1_M:
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

