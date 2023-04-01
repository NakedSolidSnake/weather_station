#ifndef UDP_CONTROLLER_H
#define UDP_CONTROLLER_H

#include <udp.h>

typedef struct 
{
    udp_t udp;
} udp_controller_t;

typedef struct 
{
    udp_args_t udp;
} udp_controller_args_t;

bool udp_controller_init (udp_controller_t *object);
bool udp_controller_open (udp_controller_t *object, udp_controller_args_t *args);
bool udp_controller_run (udp_controller_t *object);
bool udp_controller_close (udp_controller_t *object);

#endif/* UDP_CONTROLLER_H */
