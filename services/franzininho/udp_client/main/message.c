#include "message.h"
#include "common.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

bool message_format (message_t *object, char *sensor, float value)
{
    bool status = false;
    struct tm *info;
    char datetime [50];
    time_t now;

    if (object != NULL && sensor != NULL)
    {
        now = time (NULL);
        info = localtime (&now);

        strftime (datetime, 50, "%d/%m/%Y %H:%M:%S", info);

        snprintf (object->buffer, 200, FORMAT, sensor, value, datetime);
        status = true;
    }

    return status;
}
