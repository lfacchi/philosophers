//
// Created by lon on 9/30/23.
//
#include "philo.h"

void *big_brother(void *params)
{
    t_parameter *param = NULL;
	t_table *table;
    param = (t_parameter *)params;
	table = param->table;
	long long hungry_time;
    int is_finished;
	int i;

	while (1)
	{
		i = 0;
		while (i < table->n_philos)
		{
			// Verifique se o filósofo comeu a mais tempo que o tempo de morte

			hungry_time = time_on_app(table) - table->philosophers[i].last_meal;
			is_finished = check_meals(table);
            if (is_finished == 1)
                exit(1);
			if (hungry_time > table->t_die)
			{
            printf("%d has died\n", i);

				// Libere o mutex da tabela antes de sair
				exit(1);
			}

			i++;
		}

		usleep(1000); // 1 milissegundo (1000 microssegundos)
	}
}

int check_meals(t_table *table)
{
	int i;
	int finished;
	if (table->max_meals == 0)
		return 0;
	else
	{
		finished = 0;
		i = -1;
		while (++i < table->n_philos)
		{
			if (table->philosophers[i].n_meals == table->max_meals)
				finished++;
			if (finished == table->n_philos)
				return (1);
		}
    return (0);
	}
}

