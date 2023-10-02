#include "philo.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
// Função para iniciar a mesa
t_table initialize_table(char **argv)
{
	t_table table;
	pthread_mutex_t *forks;
	pthread_mutex_t *table_mutex;
//	pthread_mutex_t *philo_mutex;
	struct t_philo *philosophers;
	int i;


	table.max_meals = 0;
	table.n_philos = ft_atoi(argv[1]);
	table.t_die = ft_atoi(argv[2]);
	table.t_eat = ft_atoi(argv[3]);
	table.t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table.max_meals = ft_atoi(argv[5]);
	table.start_time = current_time_ms();
	table_mutex = malloc(sizeof(pthread_mutex_t));
    table.table_mutex = table_mutex;
    pthread_mutex_init(table.table_mutex, NULL);
	forks = malloc(sizeof(pthread_mutex_t) * table.n_philos);
	philosophers = malloc(sizeof(t_philo) * table.n_philos);

//	table.philo_mutex = philo_mutex;
	table.philosophers = philosophers;
	i = -1;
	table.forks = forks;

	while (++i < table.n_philos)
	{
		table.philosophers[i].id = i;
		pthread_mutex_init(&forks[i], NULL);
//		pthread_mutex_init(&table.philo_mutex[i], NULL);
	}

	return table;
}

void start_dinner(t_table *table)
{
	t_parameter **params;
	int i;
	params = (t_parameter **)malloc(sizeof(t_parameter *) * table->n_philos);

	i = -1;
	while (++i < table->n_philos)
	{
		params[i] = (t_parameter *)malloc(sizeof(t_parameter));

		params[i]->philo = &table->philosophers[i];
		params[i]->table = table;
		if (pthread_create(&table->philosophers[i].thrd,
            NULL, philosopher, params[i]) != 0)
		{
			perror("Failed to create thread");
			exit(EXIT_FAILURE);
		}

	}

	pthread_mutex_lock(table->table_mutex);
	pthread_create(&table->big_brother,
                   NULL, big_brother, params[0]);
	pthread_mutex_unlock(table->table_mutex);

	// Aguardar filósofos terminarem
	i = -1;
	while (++i < table->n_philos)
		pthread_join(table->philosophers[i].thrd, NULL);
	// Destruir garfos
	pthread_mutex_lock(table->table_mutex);
	i = -1;
	while (++i < table->n_philos)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_unlock(table->table_mutex);

	i = 0;
	while (i < table->n_philos)
	{
		free(params[i]);
		i++;
	}
}

void *philosopher(void *params)
{
	t_parameter *param;
	t_philo *philo;
	t_table *table;
	int id;

	param = (t_parameter *)params;
	philo = param->philo;
	table = param->table;
	id = philo->id;

	if (id % 2 == 0)
		usleep(1000);

	while (1)
	{
		think(table, id);
		take_forks(table, id);
		eat(table, id);
		printf("n_meals:%d - philo:%d\n", table->philosophers[id].n_meals, id);
	}
}

#pragma clang diagnostic pop