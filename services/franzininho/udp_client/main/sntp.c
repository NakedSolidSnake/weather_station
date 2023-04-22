#include "sntp.h"
#include <time.h>
#include "common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_sntp.h"
#include "esp_log.h"
#include <lwip/netdb.h>

static void sntp_initialize (void);
static void sntp_time_sync_notification (struct timeval *tv);

void sntp_update_time (void)
{
    sntp_initialize();

    int retry = 0;
    const int retry_count = 15;
    while (sntp_get_sync_status() == SNTP_SYNC_STATUS_RESET && ++retry < retry_count)
    {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}

static void sntp_initialize (void)
{
    ESP_LOGI(TAG, "Initializing SNTP");
    sntp_setoperatingmode (SNTP_OPMODE_POLL);

/*
 * If 'NTP over DHCP' is enabled, we set dynamic pool address
 * as a 'secondary' server. It will act as a fallback server in case that address
 * provided via NTP over DHCP is not accessible
 */
#if LWIP_DHCP_GET_NTP_SRV && SNTP_MAX_SERVERS > 1
    sntp_setservername(1, "pool.ntp.org");

#if LWIP_IPV6 && SNTP_MAX_SERVERS > 2          // statically assigned IPv6 address is also possible
    ip_addr_t ip6;
    if (ipaddr_aton("2a01:3f7::1", &ip6)) {    // ipv6 ntp source "ntp.netnod.se"
        sntp_setserver(2, &ip6);
    }
#endif  /* LWIP_IPV6 */

#else   /* LWIP_DHCP_GET_NTP_SRV && (SNTP_MAX_SERVERS > 1) */
    // otherwise, use DNS address from a pool
    sntp_setservername (0, CONFIG_SNTP_TIME_SERVER);

    sntp_setservername (1, "pool.ntp.org");     // set the secondary NTP server (will be used only if SNTP_MAX_SERVERS > 1)
#endif

    sntp_set_time_sync_notification_cb (sntp_time_sync_notification);

    sntp_init ();

    ESP_LOGI(TAG, "List of configured NTP servers:");

    for (uint8_t i = 0; i < SNTP_MAX_SERVERS; ++i)
    {
        if (sntp_getservername (i))
        {
            ESP_LOGI (TAG, "server %d: %s", i, sntp_getservername (i));
        }
        else
        {
            // we have either IPv4 or IPv6 address, let's print it
            char buff[INET6_ADDRSTRLEN];
            ip_addr_t const *ip = sntp_getserver (i);
            if (ipaddr_ntoa_r (ip, buff, INET6_ADDRSTRLEN) != NULL)
                ESP_LOGI(TAG, "server %d: %s", i, buff);
        }
    }
}

static void sntp_time_sync_notification (struct timeval *tv)
{
    ESP_LOGI (TAG, "Notification of a time synchronization event");
}