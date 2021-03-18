/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Source file containing the ball movement related functions. The
 * ball has two axes along which it moves, the rows and the columns.
 * Therefore there is a function for both the row movement and the
 * column movement.
 */

#include "system.h"
#include "end.h"
#include "move.h"

/** Set the direction the ball moves across the rows. */
int set_row_movement(int i, int current)
{
    if (i == 6) {
        return -1;
    } else if (i == 0) {
        return 1;
    } else {
        return current;
    }
}


/** Determine angle the bal releases from board. */
int release_angle(int i, int position) {
    if (position == i) {
        return -1;
    } else if (position+1 == i) {
        return 0;
    } else if (position+2 == i) {
        return 1;
    } else {
        return 2;
    }
}

