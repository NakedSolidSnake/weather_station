#include "temperature.h"
#include <string.h>
#include "esp_system.h"

bool temperature_init (temperature_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (temperature_t));
        status = true;
    }

    return status;
}

bool temperature_open (temperature_t *object, temperature_args_t *args)
{
    bool status = false;

    if (object != NULL && args != NULL)
    {
        object->type = DHT_TYPE_DHT11;
        object->pin = args->pin;

        gpio_set_pull_mode (object->pin, 0);
        status = true;
    }

    return status;
}

bool temperature_get_values (temperature_t *object, temperature_values_t *values)
{
    bool status = false;

    if (object != NULL && values != NULL)
    {
        if (dht_read_float_data (object->type,
                                 object->pin,
                                 &values->humidity,
                                 &values->temperature) == ESP_OK)
        {
            status = true;
        }
    }

    return status;
}