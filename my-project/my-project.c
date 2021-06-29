#include "api.h"
#include "api-asm.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define PORT_LED GPIOC
#define PIN_LED GPIO8


int main(void)
{
	int i;
	short j = 0;

	gpio_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		/* Manually: */
		// GPIOC_BSRR = PIN_LED;		/* LED off */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		//	__asm__("nop");
		// GPIOC_BRR = PIN_LED;			/* LED on */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		//	__asm__("nop");

		/* Using API functions gpio_set()/gpio_clear(): */
		// gpio_set(PORT_LED, PIN_LED);		/* LED off */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		//	__asm__("nop");
		// gpio_clear(PORT_LED, PIN_LED);	/* LED on */
		// for (i = 0; i < 1000000; i++)	/* Wait a bit. */
		//	__asm__("nop");

		/* Using API function gpio_toggle(): */
		gpio_toggle(PORT_LED, PIN_LED);	/* LED on/off */
		for (i = 0; i < (j <= 4 ? 500000 : 250000); i++) {	/* Wait a bit. */
			__asm__("nop");
		}

		if (++j == 10)  {
			j = 0;
		}
	}

	return 0;
}

