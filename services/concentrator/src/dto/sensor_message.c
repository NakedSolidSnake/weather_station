#include <sensor_message.h>
#include <string.h>
#include <stdio.h>
#include <sat.h>

#define SENSOR_MESSAGE_DATE_FORMAT  "%d/%m/%Y %H:%M:%S"
#define SENSOR_MESSAGE_AMOUNT       3
#define SENSOR_MESSAGE_TEMPERATURE  "temperature"
#define SENSOR_MESSAGE_HUMIDITY     "humidity"
#define SENSOR_MESSAGE_BAROMETRY    "barometry"
#define SENSOR_MESSAGE_UNDEFINED    "undefined"

typedef struct 
{
    char *string;
    sensor_type_t type;
} sensor_message_type_t;

typedef struct 
{
    sensor_message_type_t types [SENSOR_MESSAGE_AMOUNT];
    uint8_t amount;
} sensor_message_map_t;

static sensor_message_map_t map = 
{
    .types = 
    {
        {.string = SENSOR_MESSAGE_TEMPERATURE, .type = sensor_type_temperature},
        {.string = SENSOR_MESSAGE_HUMIDITY, .type = sensor_type_humidity},
        {.string = SENSOR_MESSAGE_BAROMETRY, .type = sensor_type_barometry},
    },
    .amount = SENSOR_MESSAGE_AMOUNT
};

static sensor_type_t sensor_message_get_type_by (const char *type_string);
static char *sensor_message_get_type_string_by (sensor_type_t type);

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

bool sensor_message_from_entity (sensor_message_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        memset (object, 0, sizeof (sensor_message_t));

        strncpy (object->type, sensor_message_get_type_string_by (sensor->type), SENSOR_MESSAGE_TYPE_SIZE);
        object->value = sensor->value;
        status = sat_time_get_date_by_epoch (object->date, SENSOR_MESSAGE_DATE_SIZE, SENSOR_MESSAGE_DATE_FORMAT, sensor->epoch);
    }

    return status;
}

bool sensor_message_to_entity (sensor_message_t *object, sensor_t *sensor)
{
    bool status = false;

    if (object != NULL && sensor != NULL)
    {
        memset (sensor, 0, sizeof (sensor_t));

        sensor->type = sensor_message_get_type_by (object->type);
        sensor->value = object->value;
        sensor->epoch = sat_time_get_epoch_by_string (object->date, SENSOR_MESSAGE_DATE_FORMAT);

        status = true;
    }

    return status;
}

static sensor_type_t sensor_message_get_type_by (const char *type_string)
{
    sensor_type_t type = sensor_type_undefined;

    for (uint8_t i = 0; i < map.amount; i++)
    {

        if (strcmp (map.types[i].string, type_string) == 0)
        {
            type = map.types [i].type;
            break;
        }
    }

    return type;
}

static char *sensor_message_get_type_string_by (sensor_type_t type)
{
    char *type_string = SENSOR_MESSAGE_UNDEFINED;

    for (uint8_t i = 0; i < map.amount; i++)
    {

        if (map.types[i].type == type)
        {
            type_string = map.types [i].string;
            break;
        }
    }

    return type_string;
}