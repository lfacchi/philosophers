#include "philo.h"

void pay_bill(t_table *table)
{
	pthread_mutex_lock(&table->big_wall_mutex);
	table->big_wall_bbb = 1;
	pthread_mutex_unlock(&table->big_wall_mutex);
}

void do_dishes(t_table *table)
{
	int i;

	t_parameter **param;
	param = (t_parameter **)table->parameter;
	// Destruir garfos
	i = -1;
	while (++i < table->n_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		free(param[i]);
		param[i] = NULL;
	}
	free(table->philosophers);
	table->philosophers =  NULL;
	free(table->forks);
	table->forks = NULL;
	free(table->parameter);
	table->parameter = NULL;
}
