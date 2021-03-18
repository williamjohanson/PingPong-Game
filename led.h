/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 */

#ifndef LED_H
#define LED_H

/** Initialise the LED's to high. */
void led_high_init(void);

/** Display the current ball position. */
void display_ball(int i, int j);

/** Dictated by the navswitch movements, display the board position. */
void display_board (int position);

#endif
