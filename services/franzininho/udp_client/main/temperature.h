#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <stdbool.h>
#include <stdint.h>
#include <dht.h>

typedef struct 
{
    dht_sensor_type_t type;
    uint8_t pin;
} temperature_t;

typedef struct 
{
    float temperature;
    float humidity;
} temperature_values_t;

typedef struct 
{
    uint8_t pin;
} temperature_args_t;

bool temperature_init (temperature_t *object);
bool temperature_open (temperature_t *object, temperature_args_t *args);
bool temperature_get_values (temperature_t *object, temperature_values_t *values);

#endif/* TEMPERATURE_H */

