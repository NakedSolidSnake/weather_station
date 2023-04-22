#include "udp_client.h"
#include "common.h"
#include <string.h>

#include "esp_log.h"

#include "lwip/err.h"
#include <lwip/netdb.h>
#include "protocol_examples_common.h"

#if defined(CONFIG_EXAMPLE_IPV4)
#define HOST_IP_ADDR CONFIG_EXAMPLE_IPV4_ADDR
#else
#define HOST_IP_ADDR ""
#endif

#define PORT CONFIG_EXAMPLE_PORT

bool udp_client_init (udp_client_t *object)
{
    bool status = false;

    char host_ip[] = HOST_IP_ADDR;
    int addr_family = 0;
    int ip_protocol = 0;

    if (object != NULL)
    {
        object->destination_address.sin_addr.s_addr = inet_addr (HOST_IP_ADDR);
        object->destination_address.sin_family = AF_INET;
        object->destination_address.sin_port = htons (PORT);
        addr_family = AF_INET;
        ip_protocol = IPPROTO_IP;

        /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
        * Read "Establishing Wi-Fi or Ethernet Connection" section in
        * examples/protocols/README.md for more information about this function.
        */
        ESP_ERROR_CHECK (example_connect ());

        object->socket = socket (addr_family, SOCK_DGRAM, ip_protocol);
        if (object->socket > 0) {
            ESP_LOGI (TAG, "Socket created, sending to %s:%d", HOST_IP_ADDR, PORT);
            status = true;            
        }
    }

    return status;
}
bool udp_client_send (udp_client_t *object, void *buffer, uint16_t size)
{
    bool status = false;
    int error;

    if (object != NULL && buffer != NULL && size > 0)
    {
        error = sendto (object->socket,
                        buffer,
                        size,
                        0,
                        (struct sockaddr *)&object->destination_address,
                        sizeof(object->destination_address));
        if (error < 0)
        {
            ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
        }
        else
            status = true;
    }

    return status;
}

bool udp_client_close (udp_client_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        shutdown(object->socket, 0);
        close(object->socket);
        status = true;
    }

    return status;
}