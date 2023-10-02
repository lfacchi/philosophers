#include "philo.h"

int main (int argc, char **argv)
{
    t_table table;
	int i;

    table = initialize_table(argv);
    start_dinner(&table);
	pthread_join(table.big_brother, NULL);
	i = -1;
	while (++i < table.n_philos)
		pthread_join(table.philosophers[i].thrd, NULL);
	do_dishes(&table);

	return 0;
}
