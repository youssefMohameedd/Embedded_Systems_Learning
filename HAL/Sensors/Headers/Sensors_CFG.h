/*
 * LM35_CFG.h
 *
 * Created: 3/13/2025 2:22:12 AM
 *  Author: Youssef
 */ 


#ifndef LM35_CFG_H_
#define LM35_CFG_H_

// Sensors Channel and Transfer function definitions

#define LM35 ADC_Channel0
#define LM35_SENSITIVITY_FACTOR 100.0


//below Sensor definitions needs to be completed in the upcoming improvements

#define LDR ADC_Channel0
#define LDR_SENSITIVITY_FACTOR 

#define THERMISTOR ADC_Channel2
#define THERMISTOR_SENSITIVITY_FACTOR 

// SG : Strain Gauge
#define SG ADC_Channel3
#define SG_SENSITIVITY_FACTOR 



#endif /* LM35_CFG_H_ */