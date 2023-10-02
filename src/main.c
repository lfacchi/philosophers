#include "philo.h"

int main (int argc, char **argv)
{
    t_table table;
    table = initialize_table(argv);
    start_dinner(&table);
}
