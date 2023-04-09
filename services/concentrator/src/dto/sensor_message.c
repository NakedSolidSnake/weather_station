#include <sensor_message.h>
#include <string.h>
#include <stdio.h>

bool sensor_message_create (sensor_message_t *object, const char *type, double value, const char *date)
{
    bool status = false;

    if (object != NULL && type != NULL && date != NULL)
    {
        strncpy (object->type, type, SENSOR_MESSAGE_TYPE_SIZE);
        object->value = value;
        strncpy (object->date, date, SENSOR_MESSAGE_DATE_SIZE);

        status = true;
    }

    return status;
}

void sensor_message_print (sensor_message_t *object)
{
    if (object != NULL)
    {
        printf ("Sensor: %s, Value: %.2lf, Date: %s\n", object->type, object->value, object->date);
    }
}