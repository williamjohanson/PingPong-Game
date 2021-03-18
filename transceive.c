/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Source file containing the infra-red related functions. There is both
 * a send and a receive function.
 */

#include "system.h"
#include "end.h"
#include "ir_uart.h"
#include "transceive.h"

/** Receive and decode a character */
int get_char (void)
{
    char ch = ir_uart_getc();
    if (ch == 'A') {
        return -1;
    } else if (ch == 'B') {
        return 0;
    } else if (ch == 'C') {
        return 1;
    } else if (ch == 'D') {
        return 2;
    } else {
        return 4;
    }
}

/** Send the character as a position */
int send_char (int direction)
{
    if (direction == -1) {
        ir_uart_putc ('C');
    } else if (direction == 0) {
        ir_uart_putc ('B');
    } else if (direction == 1) {
        ir_uart_putc ('A');
    } else if (direction == 2) {
        ir_uart_putc ('D');
        return 3;
    }
    return 0;
}
