
#include <stdio.h>
#include <pthread.h>

typedef struct t_philo
{
    int init_time;
    int count_meal;
    pthread_t   thread_id;
    pthread_mutex_t	*fork[2];
    pthread_mutex_t	is_eating;
}   t_philo;

typedef struct t_table
{
    struct t_philo  *philos;
    
};


void	check_num(char **arr);