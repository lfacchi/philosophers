#include "philo.h"

// Função para iniciar a mesa
t_table  initialize_table(char **argv)
{
    t_table table;
    pthread_mutex_t *forks;
    struct t_philo *philosophers;
    int i;

    table.n_philos = ft_atoi(argv[1]);
    table.t_die = ft_atoi(argv[2]);
    table.t_eat = ft_atoi(argv[3]);
    table.t_sleep = ft_atoi(argv[4]);
    if(argv[5])
        table.max_meals = ft_atoi(argv[5]);
    table.start_time = current_time_ms();;

    forks = malloc(sizeof(pthread_mutex_t) * table.n_philos);
    philosophers = malloc(sizeof(t_philo) * table.n_philos);
    table.philosophers =  philosophers;
    i = -1;
    while(++i < table.n_philos)
        table.philosophers[i].id = i;

    table.forks = forks;
    return table;
}

void start_dinner(t_table table)
{
    t_parameter params;
    int n_trheads;
    int i;

    i = -1;
    while (++i <= table.n_philos)
    {
        params.philo = &table.philosophers[i];
        params.table = &table;
        if (i % 2 == 0)
            usleep(500);
        pthread_create(&table.philosophers[i].thrd, NULL, &philosopher, &params);
    }
    pthread_create(&table.big_brother, NULL, &big_brother, &table);
    // Aguardar filósofos terminarem
    i = -1;
    while (++i < table.n_philos)
        pthread_join(table.philosophers[i].thrd, NULL);
    // Destruir garfos
    i = -1;
    while (++i < table.n_philos)
        pthread_mutex_destroy(&table.forks[i]);
}

void *philosopher(t_parameter *param)
{
    t_philo *philo;
    t_table *table;
    int id;

    philo = param->philo;
    table = param->table;
    id = philo->id;


    while (1) {
        // Filósofo pensa
        think(table, id);
        take_forks(table, id);
        eat(table, id);
        table->philosophers[id].last_meal++;
        printf("n_meals:%d - philo:%d\n",table->philosophers[id].n_meals, id);
//        printf("last-meal:%d philo:%d\n", table->philosophers[id].last_meal, table->philosophers[id].id);
        sleeping(table, id);
    }
    return NULL;
}

#include "philo.h"

// Função do observador para verificar a morte dos filósofos
void big_brother(t_table *table)
{
    long long hungry_time;
    long long current_time;


    int i;

    while (1)
    {
        i = -1;
        current_time = current_time_ms();
        while(++i < table->n_philos)
        {
            // Calcule o tempo desde a última refeição do filósofo i
            hungry_time = time_on_app(table) - table->philosophers[i].last_meal;
//            hungry_time = time_diff_in_ms( table->start_time, hungry_time);
            // Verifique se o filósofo comer a mais tempo que io tempo de morte
            if (table->max_meals && table->philosophers[i].n_meals >= table->max_meals)
            {
                printf("n_meals:%d\n", table->philosophers[i].n_meals);
                printf("max_meals:%d\n", table->max_meals);
                exit(1);
            }
            if (hungry_time > table->t_die)
            {
                printf("%d has died\n", i);
                printf("last meal:%lld\n", table->philosophers[i].last_meal);
                printf("hungry time:%lld\n", hungry_time);
                exit(1);
            }
        }
        // Aguarde um curto período de tempo antes de verificar novamente
        usleep(1000); // 1 milissegundo (1000 microssegundos)
    }
}

