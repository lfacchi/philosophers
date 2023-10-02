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

    hungry_time = 0;
    is_finished = 0;
	while (1)
	{
		i = -1;
		while (++i < table->n_philos)
		{
			hungry_time = time_on_app(table) - table->philosophers[i].last_meal;
			is_finished = check_meals(table);
            if (is_finished == 1)
            {
                pay_bill(table);
//                return NULL;
            }
			if (hungry_time > table->t_die)
			{
                printf("%d has died\n", i);
                pay_bill(table);
//                return NULL;
			}
		}
		usleep(1000);
    }
}

int check_meals(t_table *table)
{
	int i;
	int finished;

    finished = 0;
	if (table->max_meals == 0)
		return 0;
	else
	{
		i = -1;
		while (++i < table->n_philos)
		{
			if (table->philosophers[i].finished == 1)
				finished++;
			if (finished == table->n_philos)
				return (1);
		}
    return (0);
	}
}

