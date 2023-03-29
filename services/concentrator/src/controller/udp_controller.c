#include <udp_controller.h>


bool udp_controller_init (udp_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_init (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

bool udp_controller_open (udp_controller_t *object, udp_controller_args_t *args)
{
    bool status = false;

    if (object != NULL && args != NULL)
    {
        if (udp_open (&object->udp, &args->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

bool udp_controller_run (udp_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_run (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

bool udp_controller_close (udp_controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_close (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}
