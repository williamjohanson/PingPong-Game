/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Main function that dictates the order of operations through a while
 * loop that is only broken if the game is ended (lost).
 * Also contains the board decision function which dictates which board
 * will 'serve' the ball through the push of the navswitch.
 */

#include "system.h"
#include "pio.h"
#include "pacer.h"
#include "navswitch.h"
#include "tinygl.h"
#include "../fonts/font3x5_1.h"
#include "ir_uart.h"
#include "end.h"
#include "led.h"
#include "move.h"
#include "navs.h"
#include "transceive.h"

#define PACER_RATE 100
#define MESSAGE_PACER_RATE 500
#define MESSAGE_RATE 3

/** Decide on the beginning board through a push of the navswitch push
 * button.
 */
int decide_board (void) {
    // Initialise opening message components.
    tinygl_text ("PRESS JOYSTICK\0");
    pacer_init (MESSAGE_PACER_RATE);

    // Run the message while checking to see if start button has been pushed.
    while (1) {
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

/** Main function containing game loop. */
int main (void)
{
    // Initialise board components.
    system_init ();
    navswitch_init ();
    led_high_init();
    ir_uart_init ();
    tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    pacer_init (PACER_RATE);

    // Decides which board will initialize game.
    int sender = decide_board();

    // Reset the speed of the timer.
    pacer_init (PACER_RATE);

    // Initialise variables.
    int i = 3;
    int j = 0;
    int ir_error_count = 0;
    int forwards_col = 1;
    int forwards_row = 0;
    int position = 2;
    int recv_flag = 0;
    int count = 15;
    int exit_status = 0;

    // Display the board at beginning position (center).
    navswitch_set_output();
    display_board (position);

    // Continuous while loop only broken if game ended.
    while (1)
    {
        // Stay in this while loop until receives direction signal.
        if (j == 0 && sender == 0) {
            ir_error_count = 0;
            while (ir_uart_read_ready_p() == 0) {
                display_ball(i, j);
                pacer_wait ();
                display_board (position);
                pacer_wait ();
                if (ir_error_count > 150) {
                    exit_status = 4;
                    break;
                }
                ir_error_count++;
            }
            if (exit_status == 0) {
                forwards_row = get_char();
                recv_flag = 1;
            }
            if (forwards_row >= 2) {
                exit_status = forwards_row;
            }
            forwards_col = 1;
        }

        // Display the position of the ball.
        display_ball(i, j);

        pacer_wait ();

        // Reset navswitches.
        navswitch_set_input();
        navswitch_update();

        // Check for movement by the player of the board.
        if (navswitch_push_event_p (NAVSWITCH_SOUTH) && position < 4) {
            position++;
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH) && position > 0) {
            position--;
        }

        // Change navswitch back to output and display changed board position.
        navswitch_set_output();
        display_board (position);

        pacer_wait();

        // Create a slower loop for checking position of the ball.
        if (count >= 15 || recv_flag) {
            if (j == 4) {
                forwards_col = -1;
                forwards_row = release_angle(i, position);
                exit_status = send_char(forwards_row);
            }
            forwards_row = set_row_movement(i, forwards_row);

            j += forwards_col;
            i += forwards_row;

            recv_flag = 0;
            sender = 0;
            count = 0;
        }
        count++;

        // Check if program broken if so display the end messages.
        if (exit_status != 0) {
            sender = end_program(exit_status);

            // Reset the game to start over again.
            i = 3;
            j = 0;
            forwards_col = 1;
            forwards_row = 0;
            position = 2;
            recv_flag = 0;
            count = 15;
            exit_status = 0;
            pacer_init (PACER_RATE);
            navswitch_set_output();
            display_board (position);

        }
    }

    return 0;
}
