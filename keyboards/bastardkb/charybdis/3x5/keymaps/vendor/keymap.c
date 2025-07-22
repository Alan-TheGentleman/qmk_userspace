#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    LAYER_5,
    LAYER_6,
};

enum custom_keycodes {
    CUSTOM_0 = SAFE_RANGE,
    CUSTOM_1,
    CUSTOM_2,
    CUSTOM_3,
    CUSTOM_4,
    CUSTOM_6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_3x5(
        KC_Q, KC_W, KC_E, KC_R, KC_T,
        MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G,
        LT(4, KC_Z), KC_X, KC_C, KC_V, KC_B,
        LT(1, KC_TAB), KC_NO, LT(3, KC_ESC),
        LT(2, KC_SPC), KC_NO,
        KC_P, KC_O, KC_I, KC_U, KC_Y,
        MT(MOD_LGUI | MOD_RGUI, KC_QUOT), MT(MOD_LALT, KC_L), MT(MOD_LCTL | MOD_RCTL, KC_K), MT(MOD_LSFT | MOD_RSFT, KC_J), KC_H,
        LT(4, KC_SLSH), KC_DOT, KC_COMM, KC_M, KC_N,
        LT(6, KC_ENT), KC_NO, LT(5, KC_BSPC),
        KC_NO, KC_NO
    ),
    [LAYER_1] = LAYOUT_3x5(
        KC_NO, KC_NO, KC_F7, KC_F8, KC_F9,
        KC_LSFT, KC_LALT, KC_F5, KC_F6, KC_F7,
        KC_LGUI, KC_LCTL, KC_F1, KC_F2, KC_F3,
        KC_TRNS, KC_NO, KC_NO,
        KC_NO, KC_NO,
        KC_NO, KC_9, KC_8, KC_7, KC_NO,
        KC_0, KC_6, KC_5, KC_4, KC_NO,
        KC_NO, KC_3, KC_2, KC_1, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO
    ),
    [LAYER_2] = LAYOUT_3x5(
        KC_NO, KC_NO, KC_NO, S(KC_4), KC_NO,
        KC_LSFT, S(KC_2), S(KC_3), S(KC_5), KC_NO,
        KC_GRV, KC_NO, KC_NO, S(KC_SLSH), KC_NO,
        KC_LALT, KC_NO, KC_LGUI,
        KC_TRNS, KC_NO,
        KC_NO, KC_MINS, S(KC_0), S(KC_9), S(KC_6),
        KC_SCLN, KC_EQL, S(KC_RBRC), S(KC_LBRC), S(KC_7),
        KC_SLSH, S(KC_1), KC_RBRC, KC_LBRC, S(KC_8),
        KC_ENT, KC_NO, KC_LCTL,
        KC_NO, KC_NO
    ),
    [LAYER_3] = LAYOUT_3x5(
        KC_NO, RGB_RMOD, RGB_TOG, RGB_MOD, KC_NO,
        KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_MSTP, KC_NO, KC_TRNS,
        KC_MPLY, KC_NO,
        KC_NO, RGB_MOD, RGB_TOG, RGB_RMOD, KC_NO,
        KC_MNXT, KC_VOLU, KC_MUTE, KC_VOLD, KC_MPRV,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_MSTP, KC_NO, KC_MPLY,
        KC_NO, KC_NO
    ),
    [LAYER_4] = LAYOUT_3x5(
        KC_NO, KC_NO, CUSTOM_1, CUSTOM_0, CUSTOM_2,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, CUSTOM_3,
        KC_TRNS, CUSTOM_6, CUSTOM_4, KC_NO, KC_NO,
        KC_MS_BTN3, KC_NO, KC_MS_BTN2,
        KC_MS_BTN1, KC_NO,
        KC_NO, KC_NO, CUSTOM_1, CUSTOM_0, CUSTOM_2,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, CUSTOM_3,
        KC_TRNS, CUSTOM_6, CUSTOM_4, KC_NO, KC_NO,
        KC_MS_BTN3, KC_NO, KC_MS_BTN1,
        KC_NO, KC_NO
    ),
    [LAYER_5] = LAYOUT_3x5(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,
        KC_NO, MACRO(1), MACRO(0), KC_NO, KC_NO,
        KC_RGHT, KC_DOWN, KC_UP, KC_LEFT, KC_CAPS,
        KC_END, KC_PGUP, KC_PGDN, KC_HOME, KC_INS,
        KC_NO, KC_NO, KC_TRNS,
        KC_NO, KC_NO
    ),
    [LAYER_6] = LAYOUT_3x5(
        S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC),
        S(KC_SCLN), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL),
        S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS),
        S(KC_MINS), KC_NO, S(KC_9),
        S(KC_0), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_NO, KC_NO,
        KC_NO, KC_NO
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case 0:
            return record->event.pressed ? MACRO(D(LGUI), T(MINUS), U(LGUI), END) : MACRO_NONE;
        case 1:
            return record->event.pressed ? MACRO(D(LGUI), T(PLUS), U(LGUI), END) : MACRO_NONE;
    }
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_0:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
        case CUSTOM_1:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
        case CUSTOM_2:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
        case CUSTOM_3:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
        case CUSTOM_4:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
        case CUSTOM_6:
            if (record->event.pressed) {
                // Your custom action here
            }
            return false;
    }
    return true;
}