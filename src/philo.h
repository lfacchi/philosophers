#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include "../42_libft/libft.h"

#define MAX_PHILOSOPHERS 100

typedef struct t_philo {
    int id;
    pthread_t thrd;
    long long start_time;
    long long last_meal;
    int n_meals;
}t_philo;

typedef struct t_table{
    pthread_t big_brother;
    long long start_time;
    int n_philos;
    int t_die;
    int t_eat;
    int t_sleep;
    int max_meals;
    pthread_mutex_t *forks;
    struct t_philo *philosophers;
}t_table;

typedef struct t_parameter {

    t_philo *philo;
    t_table *table;
}t_parameter;

//philo.c
t_table     initialize_table(char **argv);
void        start_dinner(t_table table);
void        *philosopher(t_parameter *param);
void        big_brother(t_table *table);


//time.c
long long         time_on_app(t_table *table);
long long         time_diff_in_ms(long long start,long long end);
long long         current_time_ms();
long long         timeval_to_ms(struct timeval t);

//actions.c
void think(t_table *table, int id);
void take_forks(t_table *table, int id);
void eat(t_table *table, int id);
void sleeping(t_table *table, int id);

#endif