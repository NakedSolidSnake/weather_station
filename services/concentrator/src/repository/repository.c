#include <repository.h>
#include <string.h>

bool repository_init (repository_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (repository_t));
        status = true;
    }

    return status;
}

bool repository_open (repository_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        object->sensors [0].type = sensor_type_temperature;
        object->sensors [1].type = sensor_type_humidity;
        object->sensors [2].type = sensor_type_barometry;
        status = true;
    }

    return status;
}

bool repository_sensor_update_by (repository_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        for (unsigned char i = 0; i < SENSOR_AMOUNT; i++)
        {
            if (sensor->type == object->sensors[i].type)
            {
                object->sensors[i].value = sensor->value;
                object->sensors[i].epoch = sensor->epoch;
                status = true;
                break;
            }
        }
    }

    return status;
}

bool repository_sensor_get_by_type (repository_t *object, sensor_type_t type, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        for (unsigned char i = 0; i < SENSOR_AMOUNT; i++)
        {
            if (type == object->sensors[i].type)
            {
                memcpy (sensor, &object->sensors[i], sizeof (sensor_t));
                status = true;
                break;
            }
        }
    }

    return status;
}

bool repository_sensor_get_all (repository_t *object, sensor_t sensors [SENSOR_AMOUNT])
{
    bool status = false;

    if (object != NULL && sensors != NULL)
    {
        memcpy (sensors, object->sensors, sizeof (object->sensors));
        status = true;
    }

    return status;
}

bool repository_close (repository_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (repository_t));
        status = true;
    }

    return status;
}