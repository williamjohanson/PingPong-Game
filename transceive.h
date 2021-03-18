/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 */

#ifndef TRANSCEIVE_H
#define TRANSCEIVE_H

/** Receive and decode a character. */
int get_char (void);

/** Send the character as a position. */
int send_char (int direction);

#endif
