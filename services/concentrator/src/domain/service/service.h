#ifndef SERVICE_H
#define SERVICE_H

#include <stdbool.h>
#include <sensor.h>

typedef struct 
{
    int dummy;
} service_t;

bool service_init (service_t *object);
bool service_open (service_t *object);
bool service_sensor_update_by (service_t *object, sensor_t *sensor);
bool service_sensor_get_by_type (service_t *object, sensor_type_t type, sensor_t *sensor);
bool service_sensor_get_all (service_t *object, sensor_t sensors [SENSOR_AMOUNT]);
bool service_close (service_t *object);

#endif/* SERVICE_H */
