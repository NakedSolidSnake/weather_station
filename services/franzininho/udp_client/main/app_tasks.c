#include "app_tasks.h"
#include "pressure.h"
#include "temperature.h"
#include "common.h"
#include "esp_log.h"
#include "udp_client.h"
#include "message.h"

void app_temperature_task (void *parameters)
{
    udp_client_t *udp = (udp_client_t *)parameters;
    temperature_t temperature;
    message_t message;

    temperature_args_t args =
    {
        .pin = 17
    };

    temperature_values_t values;

    if (temperature_init (&temperature) == false || 
        temperature_open (&temperature, &args) == false)
    {
        while (true)
        {
            ESP_LOGI (TAG, "Erro Temperature Init: %d", temperature.pin);
            vTaskDelay (2000 / portTICK_PERIOD_MS);
        }
    }

    while (true)
    {
        if (temperature_get_values (&temperature, &values) == false)
        {
            ESP_LOGI (TAG, "Erro Temperature Get Values");
        }

        message_format (&message, "temperature", values.temperature);
        udp_client_send (udp, &message, MESSAGE_BUFFER_SIZE);

        message_format (&message, "humidity", values.humidity);
        udp_client_send (udp, &message, MESSAGE_BUFFER_SIZE);

        vTaskDelay (4000 / portTICK_PERIOD_MS);
    }
}

void app_pressure_task (void *parameters)
{
    udp_client_t *udp = (udp_client_t *)parameters;

    pressure_t pressure;
    message_t message;

    pressure_args_t args =
    {
        .pin.scl = 9,
        .pin.sda = 8
    };

    pressure_values_t values;

    if (pressure_init (&pressure) == false || 
        pressure_open (&pressure, &args) == false)
    {
        while (true)
        {
            ESP_LOGI (TAG, "Erro pressure Init");
            vTaskDelay (2000 / portTICK_PERIOD_MS);
        }
    }

    while (true)
    {
        if (pressure_get_values (&pressure, &values) == false)
        {
            ESP_LOGI (TAG, "Erro Pressure Get Values");
        }

        message_format (&message, "barometry", values.pressure);
        udp_client_send (udp, &message, MESSAGE_BUFFER_SIZE);

        vTaskDelay (4000 / portTICK_PERIOD_MS);
    }
}
