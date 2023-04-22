#ifndef MESSAGE_H
#define MESSAGE_H

#include <stdbool.h>
#include <stdint.h>

#define MESSAGE_BUFFER_SIZE     200

typedef struct 
{
    char buffer [MESSAGE_BUFFER_SIZE];
} message_t;

bool message_format (message_t *object, char *sensor, float value);

#endif/* MESSAGE_H */
