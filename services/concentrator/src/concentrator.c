#include <concentrator.h>
#include <udp_events.h>

static bool concentrator_udp_controller_open (concentrator_t *object);

bool concentrator_init (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_controller_init (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

bool concentrator_open (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (concentrator_udp_controller_open (object) == true)
        {
            status = true;
        }
    }

    return status;
}

bool concentrator_run (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_controller_run (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

bool concentrator_close (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_controller_close (&object->udp) == true)
        {
            status = true;
        }
    }

    return status;
}

static bool concentrator_udp_controller_open (concentrator_t *object)
{
    bool status = false;

     udp_controller_args_t args = 
    {
        .udp = 
        {
            .type = udp_type_server,
            .port = "1234",
            .buffer = object->buffer,
            .size = BUFFER_SIZE,
            .on_receive = events_on_receive,
        }
    };

    if  (udp_controller_open (&object->udp, &args) == true)
    {
        status = true;
    }

    return status;
}