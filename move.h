/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 */

#ifndef MOVE_H
#define MOVE_H

/** Set the direction the ball moves across the rows. */
int set_row_movement(int i, int current);

/** Determine angle the bal releases from board. */
int release_angle (int i, int position);

#endif
