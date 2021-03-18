/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Source file containing the led related functions. This includes the
 * initialisation, display of the ball, and display of the board on
 * the led matrix.
 */

#include "system.h"
#include "pio.h"
#include "led.h"

/** Define PIO pins driving LED matrix rows. */
static const pio_t rows[] =
{
    LEDMAT_ROW1_PIO, LEDMAT_ROW2_PIO, LEDMAT_ROW3_PIO,
    LEDMAT_ROW4_PIO, LEDMAT_ROW5_PIO, LEDMAT_ROW6_PIO,
    LEDMAT_ROW7_PIO
};

/** Define PIO pins driving LED matrix columns. */
static const pio_t cols[] =
{
    LEDMAT_COL1_PIO, LEDMAT_COL2_PIO, LEDMAT_COL3_PIO,
    LEDMAT_COL4_PIO, LEDMAT_COL5_PIO
};

/** Initialise the LED's to output high. */
void led_high_init(void)
{
    // Initialise variables.
    int i = 0;

    // Set all rows and columns high.
    for (i = 0; i < 7; i++) {
        if (i < 5) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }

}

/** Display the current ball position at (i, j) on the matrix. */
void display_ball(int i, int j)
{
    pio_output_high(rows[0]);
    pio_output_high(rows[1]);
    pio_output_high(rows[2]);
    pio_output_high(rows[3]);
    pio_output_high(rows[4]);
    pio_output_high(rows[5]);
    pio_output_high(rows[6]);
    pio_output_high(cols[0]);
    pio_output_high(cols[1]);
    pio_output_high(cols[2]);
    pio_output_high(cols[3]);
    pio_output_high(cols[4]);
    pio_output_low (rows[i]);
    pio_output_low (cols[j]);
}

/** Dictated by the navswitch movements, display the board position. */
void display_board (int position)
{
    // Initialise variables
    int i = 0;
    int j = 0;
    int k = 0;

    // Set the rows low that the board is positioned in and the others high.
    for (i = 0; i < 7; i++) {
        pio_output_high(rows[i]);
    }

    for (j = 0; j < 4; j++) {
        pio_output_high(cols[j]);
    }
    pio_output_low(cols[4]);

    for (k = 0; k < 3; k++) {
        pio_output_low(rows[k + position]);
    }
}
