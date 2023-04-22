#include "pressure.h"
#include <string.h>

bool pressure_init (pressure_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (pressure_t));
        status = true;
    }

    return status;
}

bool pressure_open (pressure_t *object, pressure_args_t *args)
{
    bool status = false;
    bmp280_params_t params;

    if (object != NULL && args != NULL)
    {
        object->pin.scl = args->pin.scl;
        object->pin.sda = args->pin.sda;
        
        bmp280_init_default_params (&params);   

        ESP_ERROR_CHECK (i2cdev_init ());     

        ESP_ERROR_CHECK (bmp280_init_desc (&object->handle,
                                           BMP280_I2C_ADDRESS_0,
                                           0,
                                           object->pin.sda,
                                           object->pin.scl));

        ESP_ERROR_CHECK (bmp280_init (&object->handle, &params));

        status = true;
    }

    return status;
}

bool pressure_get_values (pressure_t *object, pressure_values_t *values)
{
    bool status = false;

    if (object != NULL && values != NULL)
    {
        if (bmp280_read_float (&object->handle,
                               &values->temperature,
                               &values->pressure,
                               &values->humidity) == ESP_OK)
        {
            status = true;
        }
    }

    return status;
}