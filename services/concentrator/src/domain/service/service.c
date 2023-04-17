#include <service.h>
#include <string.h>
#include <stdio.h>

static bool service_create_new_file (service_t *object);

bool service_init (service_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (service_t));
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
        service_write_csv (object, sensor);
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

bool service_write_csv (service_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {

        service_create_new_file (object);

        memset (object->buffer, 0, SERVICE_FILE_BUFFER);
        snprintf (object->buffer, SERVICE_FILE_BUFFER, SERVICE_FILE_FORMAT, sensor->type, sensor->value, sensor->epoch);
        sat_file_write (&object->file, object->buffer, strlen (object->buffer));
        status = true;
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

static bool service_create_new_file (service_t *object)
{
    bool status = false;

    time_t current = sat_time_get_epoch_now ();

    if (current > (object->last_open + SERVICE_FILE_TIME_OPEN))
    {
        snprintf (object->buffer, SERVICE_FILE_BUFFER, "%ld.csv", current);

        sat_file_close (&object->file);
        sat_file_open (&object->file, object->buffer, sat_file_mode_append);
        sat_file_write (&object->file, SERVICE_FILE_HEADER, strlen (SERVICE_FILE_HEADER));
        object->last_open = current;
        status = true;
    }
    return status;
}