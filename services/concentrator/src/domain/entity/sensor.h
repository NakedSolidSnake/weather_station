#ifndef SENSOR_H
#define SENSOR_H

#include <time.h>

#define SENSOR_AMOUNT   3
typedef enum 
{
    sensor_type_temperature = 1,
    sensor_type_humidity,
    sensor_type_barometry,
    sensor_type_undefined = 99
} sensor_type_t;

typedef struct 
{
    sensor_type_t type;
    double value;
    time_t epoch;
} sensor_t;

void sensor_print (sensor_t *object);

#endif/* SENSOR_H */
