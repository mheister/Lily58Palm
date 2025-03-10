#include "action_code.h"
#include "keycode.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H
#include <stdint.h>
#include <stdlib.h>

#define OLED_BL_INCREMENT 20

enum custom_keycodes { //
    CKC_OLED_ONOFF = SAFE_RANGE,
    CKC_OLED_BLUP,
    CKC_OLED_BLDOWN
};

enum layer_number {
    _QWERTY = 0,
    _FN,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | `ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  _   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | `    |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | PGUP |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  Tab  |    | Enter |------+------+------+------+------+------|
     * | PGDN |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  -   |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                     [FN] | CTRL | Del  | / <---  /       \Space \  | AltGr|      |  [FN]
     *                          |      | [SFT]|/       /         \      \ |      |      |
     *                          `---------------------'           '------''-------------'
     */
    [_QWERTY] = LAYOUT(                                                                                                                                  //
        GRAVE_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_UNDS,                                                                  //
        KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQUAL,                                                                    //
        KC_PGUP, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, //
        KC_PGDN, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TAB, KC_ENT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINUS,                                           //
        MO(_FN), KC_LCTL, LSFT_T(KC_DEL), KC_BACKSPACE, KC_SPC, KC_RALT, _______, MO(_FN)),

    /* FN
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      | mouU | SPC  | mBtn2| OLED |                    |      |   {  |   }  |   [  |   ]  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | HOME | mouL | mouD | mouR | mBtn1| OLUP |-------.    ,-------| Left | Down |  Up  |Right |  SPC |   ~  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * | END  |      |  INS |      | mBtn3| OLDN |-------|    |-------|   %  |   _  |   -  |  +   |   \  |   |  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                     [FN] |      |      | / Space /       \ <--- \  |      |      |  [FN]
     *                          |      |      |/       /         \      \ |      |      |
     *                          `---------------------'           '------''-------------'
     */
    [_FN] = LAYOUT(                                                                                                                                //
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,                                                    //
        _______, _______, KC_MS_UP, KC_SPC, KC_MS_BTN2, CKC_OLED_ONOFF, _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12,                       //
        KC_HOME, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN1, CKC_OLED_BLUP, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SPC, KC_TILD,               //
        KC_END, _______, KC_INSERT, _______, KC_MS_BTN3, CKC_OLED_BLDOWN, _______, _______, KC_PERC, KC_UNDS, KC_MINUS, KC_PLUS, KC_BSLS, KC_PIPE, //
        KC_TRNS, _______, _______, KC_SPC, KC_BACKSPACE, _______, _______, KC_TRNS),

    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                     [FN] |      |      | /       /       \      \  |      |      |  [FN]
     *                          |      |      |/       /         \      \ |      |      |
     *                          `---------------------'           '------''-------------'
     */
    [_RAISE] = LAYOUT(                                                                                                                //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   //
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, //
        _______, _______, _______, _______, _______, _______, _______, _______),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                     [FN] |      |      | /       /       \      \  |      |      |  [FN]
     *                          |      |      |/       /         \      \ |      |      |
     *                          `---------------------'           '------''-------------'
     */
    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _FN, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        char buf[8];
        oled_write_ln(itoa(oled_get_brightness(), buf, 10), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();

#ifdef OLED_ENABLE
        switch (keycode) {
            case CKC_OLED_ONOFF:
                if (is_oled_on()) {
                    oled_off();
                } else {
                    oled_on();
                }
                break;
            case CKC_OLED_BLUP: {
                uint8_t brightness = oled_get_brightness();
                if (brightness > UINT8_MAX - OLED_BL_INCREMENT) {
                    brightness = UINT8_MAX - OLED_BL_INCREMENT;
                }
                oled_set_brightness(brightness + OLED_BL_INCREMENT);
            } break;
            case CKC_OLED_BLDOWN: {
                uint8_t brightness = oled_get_brightness();
                if (brightness < OLED_BL_INCREMENT) {
                    brightness = OLED_BL_INCREMENT;
                }
                oled_set_brightness(brightness - OLED_BL_INCREMENT);
            } break;
        }
#endif
    }
    return true;
}

void suspend_power_down_user() {
#ifdef OLED_ENABLE
    oled_off();
#endif
}
