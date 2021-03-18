/* - William Johanson
 * - Ollie Sharplin
 * ENCE260 Embedded Systems game assignment.
 *
 * Source file containing the navigational switch functions. This
 * includes a function setting the navswitch pins high and the navswitch
 * pins low. The need for both is to reduce flickering.
 */

#include "system.h"
#include "navswitch.h"
#include "pio.h"
#include "navs.h"

#define NAV_INPUT 1

/** Set the navswitches as inputs. */
void navswitch_set_input(void)
{
    pio_config_set (NAVSWITCH_PUSH_PIO, NAV_INPUT);
    pio_config_set (NAVSWITCH_NORTH_PIO, NAV_INPUT);
    pio_config_set (NAVSWITCH_SOUTH_PIO, NAV_INPUT);
    pio_config_set (NAVSWITCH_EAST_PIO, NAV_INPUT);
    pio_config_set (NAVSWITCH_WEST_PIO, NAV_INPUT);
}

/** Reset the navswitches to outputs. */
void navswitch_set_output(void)
{
    pio_config_set (NAVSWITCH_PUSH_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (NAVSWITCH_NORTH_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (NAVSWITCH_SOUTH_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (NAVSWITCH_EAST_PIO, PIO_OUTPUT_HIGH);
    pio_config_set (NAVSWITCH_WEST_PIO, PIO_OUTPUT_HIGH);
}
