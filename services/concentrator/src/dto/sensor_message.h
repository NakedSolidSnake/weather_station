#ifndef SENSOR_MESSAGE_H
#define SENSOR_MESSAGE_H

#include <stdbool.h>
#include <sensor.h>

#define SENSOR_MESSAGE_TYPE_SIZE    25
#define SENSOR_MESSAGE_DATE_SIZE    30

typedef struct
{
    char type [SENSOR_MESSAGE_TYPE_SIZE];
    double value;
    char date [SENSOR_MESSAGE_DATE_SIZE];
} sensor_message_t;

bool sensor_message_create (sensor_message_t *object, const char *type, double value, const char *date);
void sensor_message_print (sensor_message_t *object);

bool sensor_message_from_entity (sensor_message_t *object, sensor_t *sensor);
bool sensor_message_to_entity (sensor_message_t *object, sensor_t *sensor);

#endif/* SENSOR_MESSAGE_H */
