#include <udp_events.h>
#include <stdio.h>

void events_on_receive (char *buffer, size_t *size, void *data)
{
    printf ("%s\n", buffer);
}