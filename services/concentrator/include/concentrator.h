#ifndef CONCENTRATOR_H
#define CONCENTRATOR_H

#include <udp_controller.h>
#include <web_controller.h>

#define BUFFER_SIZE 1024

typedef struct 
{
    udp_controller_t udp;
    web_controller_t web;
    char buffer [BUFFER_SIZE];
} concentrator_t;

bool concentrator_init (concentrator_t *object);
bool concentrator_open (concentrator_t *object);
bool concentrator_run (concentrator_t *object);
bool concentrator_close (concentrator_t *object);

#endif/* CONCENTRATOR_H */
