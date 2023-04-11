#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <sensor.h>
#include <stdbool.h>

typedef struct 
{
    sensor_t sensors [SENSOR_AMOUNT];
} repository_t;

bool repository_init (repository_t *object);
bool repository_open (repository_t *object);
bool repository_sensor_update_by (repository_t *object, sensor_t *sensor);
bool repository_sensor_get_by_type (repository_t *object, sensor_type_t type, sensor_t *sensor);
bool repository_sensor_get_all (repository_t *object, sensor_t sensors [SENSOR_AMOUNT]);
bool repository_close (repository_t *object);

#endif/* REPOSITORY_H */
