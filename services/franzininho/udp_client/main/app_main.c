#include "app_tasks.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_event.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "sntp.h"
#include "udp_client.h"

static udp_client_t udp;

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    udp_client_init (&udp);

    sntp_update_time ();
    
    xTaskCreate(app_temperature_task, "app_temperature_task", 4096, &udp, 5, NULL);
    xTaskCreate(app_pressure_task, "app_pressure_task", 4096, &udp, 5, NULL);
}

