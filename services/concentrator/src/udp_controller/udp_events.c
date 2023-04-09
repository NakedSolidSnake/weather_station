#include <udp_events.h>
#include <stdio.h>
#include <sensor_message_deserializer.h>

void events_on_receive (char *buffer, size_t *size, void *data)
{
    // printf ("%s\n", buffer);
    sensor_message_t message;

    sensor_message_deserializer (&message, buffer);
    sensor_message_print (&message);
}