#include <service.h>
#include <string.h>
#include <stdio.h>

bool service_init (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        printf ("%s\n", "service_init");
        status = true;
    }

    return status;
}

bool service_open (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        printf ("%s\n", "service_open");
        status = true;
    }

    return status;
}

bool service_sensor_update_by (service_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        printf ("%s\n", "service_sensor_update_by");
        status = true;
    }

    return status;
}

bool service_sensor_get_by_type (service_t *object, sensor_type_t type, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        printf ("%s\n", "service_sensor_get_by_type");
        status = true;
    }

    return status;
}

bool service_sensor_get_all (service_t *object, sensor_t sensors [SENSOR_AMOUNT])
{
    bool status = false;

    if (object != NULL && sensors != NULL)
    {
        printf ("%s\n", "service_sensor_get_all");
        status = true;
    }

    return status;
}

bool service_close (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        printf ("%s\n", "service_close");
        status = true;
    }

    return status;
}