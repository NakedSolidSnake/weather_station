#include <producer.h>
#include <time.h>

#define SENSOR_TYPE  "temperature"
#define FIX_VALUE    22.26

int main (int argc, char *argv[])
{
    producer_t producer;
    double value = 0.0;

    producer_args_t args = 
    {
        .hostname = "localhost",
        .port = "8089",
        .delay = 4000000
    };

    srand (time (NULL));

    producer_init (&producer);
    producer_open (&producer, &args);

    while (true)
    {
        value = FIX_VALUE + (rand () % 9) / 10.0;
        producer_send (&producer, SENSOR_TYPE, value);
    }

    producer_close (&producer);

    return 0;
}