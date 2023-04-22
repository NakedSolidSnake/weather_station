#ifndef PRESSURE_H
#define PRESSURE_H

#include <stdbool.h>
#include <stdint.h>
#include <bmp280.h>

typedef struct 
{
    struct 
    {
        uint8_t scl;
        uint8_t sda;
    } pin;

    bmp280_t handle;
} pressure_t;

typedef struct 
{
    float pressure;
    float temperature;
    float humidity;
} pressure_values_t;

typedef struct 
{
    struct 
    {
        uint8_t scl;
        uint8_t sda;
    } pin;
    
} pressure_args_t;

bool pressure_init (pressure_t *object);
bool pressure_open (pressure_t *object, pressure_args_t *args);
bool pressure_get_values (pressure_t *object, pressure_values_t *values);

#endif/* PRESSURE_H */
