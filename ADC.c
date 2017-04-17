#include "ADC.h"
//will need to modify to use with the 60 Hz signal from the fxn generator
//preconfigured for ADC

void ConfigureADC(void)
{
	/* ADC10 Control register 1
	 * INCH_10 = choose the temperature sensor as the analog input
	 * ADC10DIV_3 = divide ADC clock by 4 (for temperature sensor)
	 */
	ADC10CTL1 = (INCH_0);
	ADC10AE0 |= ADC10_ANALOG_INPUT_BIT;
	/* ADC10 Control register 0
	 * SREF_1: Choose 1.5V reference for temperature sensor
	 * ADC10SHT_3 = 64 ADC10CLKs (for temperature sensor)
	 */
	ADC10CTL0 = (SREF_0 | ADC10SHT_3 | REFON | ADC10ON);

	_delay_cycles(1000);			// Wait for the ADC to adjust and stabilize
	ADC10CTL0 |=  (ENC | ADC10SC);	// Enable and begin sampling and conversion
}
