#include <web_controller.h>

bool web_controller_init (web_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = webserver_init (&object->web);
    }

    return status;
}

bool web_controller_open (web_controller_t *object, web_controller_args_t *args)
{
    bool status = false;

    if (object != NULL && args != NULL)
    {
        webserver_args_t web_args = 
        {
            .port = args->web.port,
            .list = args->web.list
        };

        status = webserver_open (&object->web, &web_args);
    }

    return status;
}

bool web_controller_run (web_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = webserver_run (&object->web);
    }

    return status;
}

bool web_controller_close (web_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        status = webserver_close (&object->web);
    }

    return status;
}   