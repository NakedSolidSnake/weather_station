#include <producer.h>
#include <time.h>

#define TEMPERATURE_SENSOR  "temperature"

int main (int argc, char *argv[])
{
    producer_t producer;
    double value = 0.0;

    producer_args_t args = 
    {
        .hostname = "localhost",
        .port = "1234",
        .delay = 4000000
    };

    srand (time (NULL));

    producer_init (&producer);
    producer_open (&producer, &args);

    while (true)
    {
        value = 26.22 + (rand () % 9) / 10.0;
        producer_send (&producer, TEMPERATURE_SENSOR, value);
    }

    producer_close (&producer);

    return 0;
}