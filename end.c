/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Source file containing the end program function which displays
 * the winner/loser message when the game is won/lost.
 */
#include "system.h"
#include "pio.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "navs.h"
#include "end.h"
#include "led.h"

#define PACER_RATE 100
#define MESSAGE_PACER_RATE 500
#define MESSAGE_RATE 3

/** Call the end program to display game over message. */
int end_program (int status)
{
    // Initialise opening message components.
    pacer_init (MESSAGE_PACER_RATE);

    // Reset all the leds to high so they are all off.
    led_high_init ();

    // Display the messages on the respective boards.
    if (status == 2) {
        tinygl_text ("YOU WIN! PRESS JOYSTICK TO START AGAIN\0");
    } else if (status == 3) {
        tinygl_text ("YOU LOSE! PRESS JOYSTICK TO START AGAIN\0");
    } else {
        tinygl_text ("IR ERROR. PRESS JOYSTICK TO START AGAIN\0");
    }

    // Will not exit from message loop.
    while (1)
    {
        pacer_wait ();
        tinygl_update ();
        navswitch_set_output();
        tinygl_update ();
        pacer_wait ();
        navswitch_set_input();
        navswitch_update();
        if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
            ir_uart_putc('S');
            return 1;
        } else if (ir_uart_read_ready_p() != 0) {
            if (ir_uart_getc() == 'S') {
                return 0;
            }
        }
    }
}

