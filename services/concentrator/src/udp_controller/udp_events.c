#include <udp_events.h>
#include <stdio.h>
#include <sensor_message_deserializer.h>
#include <service.h>

void events_on_receive (char *buffer, size_t *size, void *data)
{
    // printf ("%s\n", buffer);
    service_t *service = (service_t *)data;
    sensor_message_t message;
    sensor_t sensor;

    sensor_message_deserializer (&message, buffer);
    sensor_message_to_entity (&message, &sensor);
    service_sensor_update_by (service, &sensor);
    // sensor_print (&sensor);
    // sensor_message_print (&message);
}