#ifndef PRODUCER_H
#define PRODUCER_H

#include <stdbool.h>
#include <stdint.h>
#include <udp.h>

#define BUFFER_SIZE         1024

#define DATA_FORMAT         "%d/%m/%Y %H:%M:%S"

typedef struct 
{
    char buffer [BUFFER_SIZE];
    udp_t udp;
    uint32_t delay;
} producer_t;

typedef struct 
{
    char *hostname;
    char *port;
    uint32_t delay;
} producer_args_t;

bool producer_init (producer_t *object);
bool producer_open (producer_t *object, producer_args_t *args);
bool producer_send (producer_t *object, const char *sensor, double value);
bool producer_close (producer_t *object);

#endif/* PRODUCER_H */
