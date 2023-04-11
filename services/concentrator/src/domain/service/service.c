#include <service.h>
#include <string.h>

bool service_init (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = repository_init (&object->repository);
    }

    return status;
}

bool service_open (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = repository_open (&object->repository);
    }

    return status;
}

bool service_sensor_update_by (service_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        status = repository_sensor_update_by (&object->repository, sensor);
    }

    return status;
}

bool service_sensor_get_by_type (service_t *object, sensor_type_t type, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        status = repository_sensor_get_by_type (&object->repository, type, sensor);
    }

    return status;
}

bool service_sensor_get_all (service_t *object, sensor_t sensors [SENSOR_AMOUNT])
{
    bool status = false;

    if (object != NULL && sensors != NULL)
    {
        status = repository_sensor_get_all (&object->repository, sensors);
    }

    return status;
}

bool service_close (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = repository_close (&object->repository);
    }

    return status;
}