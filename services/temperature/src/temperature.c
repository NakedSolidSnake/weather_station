#include <udp.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#define BUFFER_SIZE     1024

int main (int argc, char *argv[])
{
    char buffer [BUFFER_SIZE] = {0};
    char date_format [BUFFER_SIZE] = {0};
    time_t now;
    struct tm *info;
    char *json = "{\"sensor\":\"%s\",\"value\":%.2f,\"date\":\"%s\"}\n";

    udp_t client;
    udp_args_t args = 
    {
        .type = udp_type_client,
        .hostname = "localhost",
        .port = "1234"
    };

    udp_init (&client);
    udp_open (&client, &args);

    time (&now);
    info = localtime (&now);

    strftime (date_format, BUFFER_SIZE, "%d/%m/%Y %H:%M:%S", info);

    snprintf (buffer, BUFFER_SIZE, json, "temperature", 26.22, date_format);

    udp_send (&client, buffer, strlen (buffer));

    printf ("%s\n", buffer);

    udp_close (&client);

    return 0;
}