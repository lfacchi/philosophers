#include "philo.h"


pthread_t philosophers[MAX_PHILOSOPHERS];
pthread_t observer;
int num_philosophers;
int time_to_die;
int time_to_eat;
int time_to_sleep;
int num_times_each_philosopher_must_eat;
struct timeval *start_time;

int main (int argc, char **argv)
{
    t_table table;
    table = initialize_table(argv);
//    printf("start_time|%d|\n"
//           "n_philos|%d|\n"
//           "t_die|%d|\n"
//           "t_eat|%d|\n"
//           "t_sleep|%d|\n"
//           "max_meals|%d|\n",
//           table.start_time,
//           table.n_philos,
//           table.t_die,
//           table.t_eat,
//           table.t_sleep,
//           table.max_meals);
    start_dinner(table);

}
