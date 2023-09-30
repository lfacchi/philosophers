#include "philo.h"

void think(t_table *table, int id)
{
    long long time;

    time = time_on_app(table);
    printf("%lld ms %d is thinking\n",time, id);
}

// Função para o filósofo pegar os garfos (adquira o mutex dos garfos)
void take_forks(t_table *table, int id) {
    long long time;
    int left_fork = id;
    int right_fork = (id + 1) % table->n_philos;

    pthread_mutex_lock(&table->forks[left_fork]);
    pthread_mutex_lock(&table->forks[right_fork]);
    time = time_on_app(table);
    printf("%lld ms %d has taken a fork\n",time, id);
//    time = time_on_app(table);
    printf("%lld ms %d has taken a fork\n",time, id);
}

void eat(t_table *table, int id) {
    long long time;

    time = time_on_app(table);
    printf("%lld ms %d is eating\n", time, id);
    usleep(table->t_eat * 1000); // Tempo para comer em milissegundos
    table->philosophers[id].last_meal = time_on_app(table);

    // Desbloqueie os mutexes dos garfos após o término de comer
    int left_fork = id;
    int right_fork = (id + 1) % table->n_philos;
    pthread_mutex_unlock(&table->forks[left_fork]);
    pthread_mutex_unlock(&table->forks[right_fork]);

    table->philosophers[id].n_meals++;
}


// Função para simular o sono do filósofo (pode ser personalizada)
void sleeping(t_table *table, int id)
{
    long long time;

    time = time_on_app(table);
    printf("%lld ms %d is sleeping\n",time, id);
    usleep(table->t_sleep * 1000); // Tempo para dormir em milissegundos
}