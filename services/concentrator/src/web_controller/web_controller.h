#ifndef WEB_CONTROLLER_H
#define WEB_CONTROLLER_H

#include <webserver.h>

typedef struct 
{
    webserver_t web;
} web_controller_t;

typedef struct 
{
    webserver_args_t web;
} web_controller_args_t;

bool web_controller_init (web_controller_t *object);
bool web_controller_open (web_controller_t *object, web_controller_args_t *args);
bool web_controller_run (web_controller_t *object);
bool web_controller_close (web_controller_t *object);

#endif/* WEB_CONTROLLER_H */
