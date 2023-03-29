#include <udp_controller.h>
#include <udp_events.h>


#define BUFFER_SIZE 1024

int main (int argc, char *argv[])
{
    udp_controller_t controller;
    char buffer [BUFFER_SIZE] = {0};

    udp_controller_args_t args = 
    {
        .udp = 
        {
            .type = udp_type_server,
            .port = "1234",
            .buffer = buffer,
            .size = BUFFER_SIZE,
            .on_receive = events_on_receive,
        }
    };

    udp_controller_init (&controller);
    udp_controller_open (&controller, &args);
    udp_controller_run (&controller);
    udp_controller_close (&controller);

    return 0;
}