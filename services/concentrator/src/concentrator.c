#include <concentrator.h>
#include <udp_events.h>
#include <handlers.h>
#include <pthread.h>

static bool concentrator_udp_controller_open (concentrator_t *object);
static bool concentrator_web_controller_open (concentrator_t *object);

static void *concentrator_udp_run (void *args);
static void *concentrator_web_run (void *args);

bool concentrator_init (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_controller_init (&object->udp) == true && 
            web_controller_init (&object->web) == true)
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
        if (concentrator_udp_controller_open (object) == true &&
            concentrator_web_controller_open (object) == true)
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
        pthread_t udp_thread;
        pthread_t web_thread;

        pthread_create (&udp_thread, NULL, concentrator_udp_run, &object->udp);
        pthread_create (&web_thread, NULL, concentrator_web_run, &object->web);

        pthread_join (udp_thread, NULL);
        pthread_join (web_thread, NULL);

        status = true;
    }

    return status;
}

bool concentrator_close (concentrator_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        if (udp_controller_close (&object->udp) == true && 
            web_controller_close (&object->web) == true)
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

static bool concentrator_web_controller_open (concentrator_t *object)
{
    bool status = false;

    handle_list_t *list = (handle_list_t *)calloc (1, sizeof (handle_list_t));

    if (list != NULL)
    {
        list->handles[0].endpoint = "/";
        list->handles[0].handler = handler_index;
        list->handles[0].data = NULL;

        list->amount = 1;

        web_controller_args_t args = 
        {
            .web =
            {
                .port = "8090",
                .list = list
            }
        };

        status = web_controller_open (&object->web, &args);

        if (status == false)
            free (list);
    }

    return status;
}

static void *concentrator_udp_run (void *args)
{
    udp_controller_t *udp = (udp_controller_t *)args;
    udp_controller_run (udp);
    return NULL;
}

static void *concentrator_web_run (void *args)
{
    web_controller_t *web = (web_controller_t *)args;
    web_controller_run (web);
    return NULL;
}
