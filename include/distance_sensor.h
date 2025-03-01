#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <stdint.h>  // For uint8_t, uint16_t types

void distance_sensor_init(void);
uint16_t get_distance(void);

#endif // DISTANCE_SENSOR_H
