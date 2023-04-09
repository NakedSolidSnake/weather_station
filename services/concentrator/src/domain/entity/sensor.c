#include <sensor.h>
#include <stdio.h>

void sensor_print (sensor_t *object)
{
    printf ("Type: %d, Value: %.2lf, Date: %ld\n", object->type, object->value, object->epoch);
}