/*
 * Hasu: my personal keymap
 */
#include "keymap_common.h"


#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
     * |-----------------------------------------------------------|
     * |Contro|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|FN3     |
     * |-----------------------------------------------------------|
     * |FN4     |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|Fn2|Shift |Fn1|
     * `-----------------------------------------------------------'
     *       |Gui|Alt  |         Fn4           |FN2  |Gui|
     *       `-------------------------------------------'
     */
    [0] = \
    KEYMAP(FN5, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC, \
           FN7, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT,FN9, \
           FN4, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH, FN6,FN1, \
                FN10,FN3,          FN8,                RALT, FN11),

    /* Layer 1: HHKB mode[HHKB Fn]
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |Backs|
     * |-----------------------------------------------------------|
     * |Contro|VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow|Shift |   |
     * `-----------------------------------------------------------'
     *       |Alt|Gui  |         Space         |Gui  |Alt|
     *       ---------'
     */
    [1] = \
    KEYMAP(PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
           CAPS,NO,  HOME,UP,  PGUP,NO,  NO,  NO,  PSCR,  SLCK,  PAUS,  UP,  NO,  BSPC, \
           LCTL,NO,  LEFT,DOWN,RGHT,NO,  PAST,PSLS,HOME,  PGUP,  LEFT,   RGHT,  TRNS, \
           LSFT,NO,  END, NO,  PGDN,NO,  PPLS,PMNS,  END,  PGDN,  DOWN,  RSFT, FN1, \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),


    /* Layer 2: Mouse mode(IJKL)[Space]
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Tab  |   |   |   |   |   |MwL|MwD|McU|MwU|MwR|Wbk|Wfr|Alt-T|
     * |-----------------------------------------------------------|
     * |Contro|   |   |   |   |   |Mb2|McL|McD|McR|Mb1|   |Return  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |Mb3|Mb2|Mb1|Mb4|Mb5|   |Shift |   |
     * `-----------------------------------------------------------'
     *      |Alt |Gui  |          Mb1          |Fn   |Fn |
     *      `--------------------------------------------'
     * Mc: Mouse Cursor / Mb: Mouse Button / Mw: Mouse Wheel
     */
    [2] = \
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL, \
//         TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
           FN5, NO,  NO,  MS_U,NO,  NO,  NO,BTN1,BTN2,BTN3,  NO,  UP,  NO,  FN5, \
//         LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, QUOT,FN3,
           LCTL,NO,  MS_L,MS_D,MS_R,NO,  MS_L,MS_D,MS_U,MS_R,LEFT,RGHT, TRNS, \
//         FN4, Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, FN2, RSFT,FN1,
           LSFT,NO,  NO,  NO,  NO,  NO,  WH_L, WH_D,WH_U,WH_R,DOWN,RSFT,NO, \
//              LALT,LGUI,          FN4,                FN2, RALT),
                TRNS,TRNS,          TRNS,               TRNS,TRNS),

    [3] = \
    KEYMAP(ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,   F8,  F9,  F10,  F11,  F12,  INS,DEL, \
            TAB, Q,   W,   E,   R,   T,   Y,   U,    I,   O,    P, LBRC, RBRC, BSPC, \
           LCTL, A,   S,   D,   F,   G,   H,   J,    K,   L, SCLN, QUOT,  TRNS, \
           LSFT, Z,   X,   C,   V,   B,   N,   M, COMM, DOT, SLSH, RSFT,  NO, \
              TRNS,TRNS,           SPC,           TRNS, TRNS),

    [4] = \
    KEYMAP(FN4, NO,  NO,  NO, END,  NO,  NO,  NO,  NO,   NO,HOME, NO, NO, INS, DEL, \
            TAB, NO,  NO,  NO,  NO,  NO,  NO,PGUP,  NO,   NO,  NO, NO, NO, BSPC, \
           LCTL,NO,  NO,  NO,PGDN,  NO,LEFT,DOWN,  UP,RIGHT,  NO, NO, TRNS, \
           LSFT,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   NO,  NO,RSFT,NO, \
                TRNS,TRNS,          NO,                TRNS,  TRNS),
};



/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
    LGUI_LCURLY,
    RGUI_RCURLY,
    CTL_LAYER_ENTER,
};

enum macro_id {
    CTL_ENTER,
    VOLUP,
    ALT_TAB,
    ALT_ENTER,
};


/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [1] = ACTION_LAYER_MOMENTARY(1),                  // HHKB layer(toggle with 5 taps)
    [2] = ACTION_LAYER_TOGGLE(4),                     // Navigation Layer (IJKL)
    [3] = ACTION_LAYER_MODS(3, MOD_LALT),             // LALT with layer 3
    [4] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),         // single left shift = ( 
    [5] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_ESC),      // RGUI + ESC
    [6] = ACTION_FUNCTION_TAP(RSHIFT_RPAREN),         // single right shift = )
    [7] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),      // LControl with tap Esc
    [8] = ACTION_LAYER_TAP_KEY(2, KC_SPC),            // Mousekey layer with Space
    [9] = ACTION_FUNCTION_TAP(CTL_LAYER_ENTER),
    [10] = ACTION_FUNCTION_TAP(LGUI_LCURLY),          // single left GUI = { 
    [11] = ACTION_FUNCTION_TAP(RGUI_RCURLY),          // single right GUI = } 

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
//  [x] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),           // Function: LShift with tap '('
//  [x] = ACTION_MACRO(HELLO),                          // Macro: say hello
//  [x] = ACTION_MACRO(VOLUP),                          // Macro: media key
};


/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case CTL_ENTER:
            if (record->event.pressed) {
                // Toggle layer 3
                layer_invert(3);
                register_mods(MOD_BIT(KC_LCTL));
                return MACRO_NONE;
            } else {
                layer_invert(3);
                unregister_mods(MOD_BIT(KC_LCTL));
                return MACRO( T(ENTER), END );
            }
        case VOLUP:
            return (record->event.pressed ?
                    MACRO( D(VOLU), U(VOLU), END ) :
                    MACRO_NONE );
        case ALT_TAB:
            return (record->event.pressed ?
                    MACRO( D(LALT), D(TAB), END ) :
                    MACRO( U(TAB), END ));
	case ALT_ENTER:
	    return (record->event.pressed ?
	 	    MACRO( D(RALT), D(ENTER), END ) :
		    MACRO( U(ENTER), END ));
    }
    return MACRO_NONE;
}



/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) dprint("P"); else dprint("R");
    dprintf("%d", record->tap.count);
    if (record->tap.interrupted) dprint("i");
    dprint("\n");

    switch (id) {
        case LSHIFT_LPAREN:
            // Shift parentheses example: LShft + tap '('
            // http://stevelosh.com/blog/2012/10/a-modern-space-cadet/#shift-parentheses
            // http://geekhack.org/index.php?topic=41989.msg1304899#msg1304899
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_LSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_9);
                    unregister_code(KC_9);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            break;
        case RSHIFT_RPAREN:
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_RSHIFT));
                    }
                } else {
                    register_mods(MOD_BIT(KC_RSHIFT));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    register_code(KC_0);
                    unregister_code(KC_0);
                    del_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_RSHIFT));
                }
            }
            break;        
        case LGUI_LCURLY:
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_LGUI));
                    }
                } else {
                    register_mods(MOD_BIT(KC_LGUI));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    register_code(KC_LBRC);
                    unregister_code(KC_LBRC);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_LGUI));
                }
            }
            break;        
        case RGUI_RCURLY:
            if (record->event.pressed) {
                if (record->tap.count > 0 && !record->tap.interrupted) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        register_mods(MOD_BIT(KC_RGUI));
                    }
                } else {
                    register_mods(MOD_BIT(KC_RGUI));
                }
            } else {
                if (record->tap.count > 0 && !(record->tap.interrupted)) {
                    add_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    register_code(KC_RBRC);
                    unregister_code(KC_RBRC);
                    del_weak_mods(MOD_BIT(KC_RSHIFT));
                    send_keyboard_report();
                    record->tap.count = 0;  // ad hoc: cancel tap
                } else {
                    unregister_mods(MOD_BIT(KC_RGUI));
                }
            }
            break;        
        case CTL_LAYER_ENTER:
            if (record->event.pressed) {
                 if (record->tap.count == 0) {
                    layer_invert(3);
                    register_mods(MOD_BIT(KC_RCTL));
                 } else {
                    register_code(KC_ENTER); 
                 }
            } else {
                if (record->tap.count == 0) {
                    layer_invert(3);
                    unregister_mods(MOD_BIT(KC_RCTL));
                } else {
                    unregister_code(KC_ENTER);
                }
            }
            break;
    }
}
