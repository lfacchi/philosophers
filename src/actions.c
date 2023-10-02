#include "philo.h"

void think(t_table *table, int id)
{
	long long time;


	if (table->big_wall_bbb)
		return ;
	time = time_on_app(table);
	printf("%lld ms %d is thinking\n", time, id);
}

void take_forks(t_table *table, int id)
{
	long long time;
	int left_fork;
	int right_fork;

	left_fork = id;
	if (id + 1 == table->n_philos)
		right_fork = 0;
	else
	{
		left_fork = id;
		right_fork = id + 1;
	}

	pthread_mutex_lock(&table->forks[left_fork]);
	pthread_mutex_lock(&table->forks[right_fork]);
	time = time_on_app(table);
	if (table->big_wall_bbb)
	{
		pthread_mutex_unlock(&table->forks[left_fork]);
		pthread_mutex_unlock(&table->forks[right_fork]);
		return ;
	}
	printf("%lld ms %d has taken a fork\n", time, id);
	time = time_on_app(table);
	printf("%lld ms %d has taken a fork\n", time, id);
}

void eat(t_table *table, int id)
{
	long long time;

	if (table->big_wall_bbb)
		return ;
	time = time_on_app(table);
	printf("%lld ms %d is eating\n", time, id);
	usleep(table->t_eat * 1000); // Tempo para comer em milissegundos
	table->philosophers[id].last_meal = time_on_app(table);
	table->philosophers[id].n_meals++;
    if (table->philosophers[id].n_meals == table->max_meals)
        table->philosophers[id].finished++;
	int left_fork = id;
	int right_fork = (id + 1) % table->n_philos;
	pthread_mutex_unlock(&table->forks[left_fork]);
	pthread_mutex_unlock(&table->forks[right_fork]);
}

void sleeping(t_table *table, int id)
{
	long long time;

	if (table->big_wall_bbb)
		return ;
	time = time_on_app(table);
	printf("%lld ms %d is sleeping\n", time, id);
	usleep(table->t_sleep * 1000);
}
