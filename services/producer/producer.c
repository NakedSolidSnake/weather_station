#include <producer.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char *JSON_FORMAT = "{\"sensor\":\"%s\",\"value\":%.2f,\"date\":\"%s\"}\n";

bool producer_init (producer_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (producer_t));
        status = true;
    }

    return status;
}

bool producer_open (producer_t *object, producer_args_t *args)
{
    bool status = false;

    if (object != NULL && args != NULL)
    {
        object->delay = args->delay;

        udp_args_t udp_args = 
        {
            .type = udp_type_client,
            .hostname = args->hostname,
            .port = args->port
        };

        status = udp_open (&object->udp, &udp_args);
    }

    return status;
}
bool producer_send (producer_t *object, const char *sensor, double value)
{
    bool status = false;
    
    char date_format [BUFFER_SIZE] = {0};
    time_t now;
    struct tm *info;

    if (object != NULL && sensor != NULL)
    {
        time (&now);
        info = localtime (&now);

        strftime (date_format, BUFFER_SIZE, DATA_FORMAT, info);

        snprintf (object->buffer, BUFFER_SIZE, JSON_FORMAT, sensor, value, date_format);

        status = udp_send (&object->udp, object->buffer, strlen (object->buffer));

        usleep (object->delay);
    }

    return status;
}

bool producer_close (producer_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        udp_close (&object->udp);
        memset (object, 0, sizeof (producer_t));
        status = true;
    }

    return status;
}