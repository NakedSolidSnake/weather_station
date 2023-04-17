#ifndef SERVICE_H
#define SERVICE_H

#include <stdbool.h>
#include <sensor.h>
#include <repository.h>
#include <sat.h>

#define SERVICE_FILE_HEADER     "sensor,value, time"
#define SERVICE_FILE_FORMAT     "\n%d,%.2lf,%ld"
#define SERVICE_FILE_BUFFER     1024
#define SERVICE_FILE_TIME_OPEN  5

typedef struct 
{
    repository_t repository;
    sat_file_t file;
    char buffer [SERVICE_FILE_BUFFER];
    time_t last_open;
} service_t;

bool service_init (service_t *object);
bool service_open (service_t *object);
bool service_sensor_update_by (service_t *object, sensor_t *sensor);
bool service_sensor_get_by_type (service_t *object, sensor_type_t type, sensor_t *sensor);
bool service_sensor_get_all (service_t *object, sensor_t sensors [SENSOR_AMOUNT]);
bool service_write_csv (service_t *object, sensor_t *sensor);
bool service_close (service_t *object);

#endif/* SERVICE_H */
