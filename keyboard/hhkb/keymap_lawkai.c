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
    KEYMAP( ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0, MINS,  EQL, BSLS,  GRV, \
            FN7,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P, LBRC, RBRC, BSPC, \
            FN2,    A,    S,    D,    F,    G,    H,    J,    K,    L, SCLN, QUOT,  FN5, \
           LSFT,    Z,    X,    C,    V,    B,    N,    M, COMM,  DOT, SLSH, RSFT,  FN4, \
                 LALT, LGUI,              FN3,             RGUI, RALT),

    [1] = \
    KEYMAP(  FN6,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL, \
            TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
            TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LEFT, DOWN,   UP, RGHT, TRNS, GRV, TRNS, \
            TRNS, HOME,  END, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PGUP, PGDN, TRNS, TRNS, \
                  TRNS, TRNS,             TRNS,             TRNS, TRNS),

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
    [2] = \
    KEYMAP( PWR,   F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,  F10,  F11,  F12,  INS,  DEL, \
             NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO, PSCR, SLCK, PAUS,   UP,   NO, BSPC, \
           TRNS, VOLD, VOLU, MUTE,  FN4,   NO, PAST, PSLS, HOME, PGUP, LEFT, RGHT, TRNS, \
           TRNS,   NO,  END,   NO,   NO,   NO, PPLS, PMNS,  END, PGDN, DOWN, TRNS, TRNS, \
                 TRNS, TRNS,             TRNS,             TRNS, TRNS),

};



/* id for user defined functions */
enum function_id {
    LSHIFT_LPAREN,
    RSHIFT_RPAREN,
    LGUI_LCURLY,
    RGUI_RCURLY,
    MEH_COLON,
    MEH_TAB,
};

enum macro_id {
    CTL_ENTER,
    CLIP_BOARD,
    TILDE_KEY,
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_DEFAULT_LAYER_SET(0),              
    [1] = ACTION_LAYER_MOMENTARY(2),                 

    [2] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),      
    [3] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [4] = ACTION_FUNCTION_TAP(MEH_COLON),
    [5] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT),      
    [6] = ACTION_MACRO(TILDE_KEY),
    [7] = ACTION_FUNCTION_TAP(MEH_TAB),
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
                layer_invert(1);
                register_mods(MOD_BIT(KC_LCTL));
                return MACRO_NONE;
            } else {
                layer_invert(1);
                unregister_mods(MOD_BIT(KC_LCTL));
                return MACRO( T(ENTER), END );
            }
        case TILDE_KEY:
            return (record->event.pressed ?
                    MACRO( D(LSFT), D(SPACE), U(SPACE), D(GRV), U(GRV), U(LSFT), END ) :
                    MACRO_NONE);
    }
    return MACRO_NONE;
}



/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case MEH_TAB:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        // ad hoc: set 0 to cancel tap
                        record->tap.count = 0;
                        add_weak_mods(MOD_BIT(KC_LALT));
                        add_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                        add_weak_mods(MOD_BIT(KC_LSHIFT));
                        send_keyboard_report();
                    } else {
                        send_keyboard_report();
                        register_code(KC_TAB);
                    }
                  } else {
                        add_weak_mods(MOD_BIT(KC_LALT));
                        add_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                        add_weak_mods(MOD_BIT(KC_LSHIFT));
                        send_keyboard_report();
                }
            } else {
                if (record->tap.count > 0) {
                    unregister_code(KC_TAB);
                    send_keyboard_report();
                } else {
                    del_weak_mods(MOD_BIT(KC_LALT));
                    del_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                }
            }
            break;
        case MEH_COLON:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    if (record->tap.interrupted) {
                        dprint("tap interrupted\n");
                        // ad hoc: set 0 to cancel tap
                        record->tap.count = 0;
                        add_weak_mods(MOD_BIT(KC_LALT));
                        add_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                        add_weak_mods(MOD_BIT(KC_LSHIFT));
                        send_keyboard_report();
                    } else {
                        dprint("MODS_TAP: Tap: register_code\n");
                        add_weak_mods(MOD_BIT(KC_LSHIFT));
                        send_keyboard_report();
                        register_code(KC_SCOLON);
                    }
                  } else {
                        add_weak_mods(MOD_BIT(KC_LALT));
                        add_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                        add_weak_mods(MOD_BIT(KC_LSHIFT));
                        send_keyboard_report();
                }
            } else {
                if (record->tap.count > 0) {
                    unregister_code(KC_SCOLON);
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                } else {
                    del_weak_mods(MOD_BIT(KC_LALT));
                    del_weak_mods(MOD_BIT(KC_LCTL));                                                                        
                    del_weak_mods(MOD_BIT(KC_LSHIFT));
                    send_keyboard_report();
                }
            }
            break;
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
    }
}
