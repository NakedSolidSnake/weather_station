#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <stdbool.h>
#include <stdint.h>
#include "lwip/sockets.h"
#include "lwip/sys.h"

typedef struct 
{
    int socket;
    struct sockaddr_in destination_address;
} udp_client_t;

bool udp_client_init (udp_client_t *object);
bool udp_client_send (udp_client_t *object, void *buffer, uint16_t size);
bool udp_client_close (udp_client_t *object);

#endif/* UDP_CLIENT_H */
