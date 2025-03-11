#ifndef METAL_DETECTOR_H
#define METAL_DETECTOR_H

#include <stdint.h>

void metal_detector_init(void);
uint8_t detect_metal(void);
void timer_init(void);
uint16_t measure_frequency(void);

#endif // METAL_DETECTOR_H
