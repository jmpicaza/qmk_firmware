#ifdef RGBLIGHT_ENABLE
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

    const rgblight_segment_t PROGMEM my_layer_QWERTY[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 0, HSV_GREEN }
    );
     // Light LEDs 11 & 12 in purple when keyboard layer 2 is active
    const rgblight_segment_t PROGMEM my_layer_NUMBERS[] = RGBLIGHT_LAYER_SEGMENTS(
        {10, 3, HSV_GREEN },
        {14, 7, HSV_GREEN}
    );
    // Light LEDs 13 & 14 in green when keyboard layer 3 is active
    const rgblight_segment_t PROGMEM my_layer_SYMBOLS[] = RGBLIGHT_LAYER_SEGMENTS(
        {6, 21, HSV_BLUE},
        {35, 2, HSV_BLUE},
        {37, 2, HSV_BLUE},
        {43, 2, HSV_BLUE},
        {45, 2, HSV_BLUE}
    );
    const rgblight_segment_t PROGMEM my_layer_MOUSE[] = RGBLIGHT_LAYER_SEGMENTS(
        {28, 28, HSV_GREEN}
    );
    const rgblight_segment_t PROGMEM my_layer_LIGTHS[] = RGBLIGHT_LAYER_SEGMENTS(
        {28, 28, HSV_PURPLE}
    );


    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        my_layer_QWERTY,   // Overrides other layers
        my_layer_NUMBERS,    // Overrides other layers
        my_layer_SYMBOLS,    // Overrides other layers
        my_layer_MOUSE,    // Overrides other layers
        my_layer_LIGTHS     // Overrides other layers
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        rgblight_layers = my_rgb_layers;
    }

//  bool led_update_user(led_t led_state) {
//      rgblight_set_layer_state(0, led_state.caps_lock);
//      return true;
//  }

    layer_state_t default_layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
        return state;
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(1, layer_state_cmp(state, _NUMBERS));
        rgblight_set_layer_state(2, layer_state_cmp(state, _SYMBOLS));
        rgblight_set_layer_state(3, layer_state_cmp(state, _MOUSE));
        rgblight_set_layer_state(4, layer_state_cmp(state, _LIGTHS));
        return state;
    }
#endif

