#include <concentrator.h>


int main (int argc, char *argv[])
{
    concentrator_t concentrator;

    concentrator_init (&concentrator);
    concentrator_open (&concentrator);
    concentrator_run (&concentrator);
    concentrator_close (&concentrator);
    
    return 0;
}