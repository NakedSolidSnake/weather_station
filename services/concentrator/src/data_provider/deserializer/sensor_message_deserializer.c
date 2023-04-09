#include <sensor_message_deserializer.h>
#include <cJSON.h>

static bool sensor_message_fill_by_json (sensor_message_t *object, cJSON *json);


bool sensor_message_deserializer (sensor_message_t *object, const char *buffer)
{
    bool status = false;
    cJSON *json = NULL;

    if (object != NULL && buffer != NULL)
    {
        json = cJSON_Parse (buffer);

        if (json != NULL)
        {
            status = sensor_message_fill_by_json (object, json);

            cJSON_Delete (json);
        }
    }


    return status;
}

static bool sensor_message_fill_by_json (sensor_message_t *object, cJSON *json)
{
    bool status = false;

    cJSON *sensor = NULL;
    cJSON *type = NULL;
    cJSON *value = NULL;
    cJSON *date = NULL;

    sensor = cJSON_CreateObject ();
    if (sensor != NULL)
    {
        type = cJSON_GetObjectItemCaseSensitive (json, "type");
        value = cJSON_GetObjectItem (json, "value");
        date = cJSON_GetObjectItemCaseSensitive (json, "date");

        status = sensor_message_create (object, type->valuestring, value->valuedouble, date->valuestring);

        cJSON_Delete (sensor);
    }

    return status;
}