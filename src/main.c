#include "philo.h"



#define MAX_PHILOSOPHERS 100

pthread_mutex_t forks[MAX_PHILOSOPHERS];
pthread_t philosophers[MAX_PHILOSOPHERS];
pthread_t observer;
int num_philosophers;
int time_to_die;
int time_to_eat;
int time_to_sleep;
int num_times_each_philosopher_must_eat;
struct timeval *start_time;

long long timeval_to_milliseconds(struct timeval t) {
    return (long long)t.tv_sec * 1000LL + (long long)t.tv_usec / 1000LL;
}

long long current_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
}

long long time_diff_in_ms(long long start, long long end) {
    return end - start;
}

void *philosopher(void *arg) {
    int id = *((int *)arg);
    int left_fork = id;
    int right_fork = (id + 1) % num_philosophers;

    while (1) {
        // Pensar
        struct timeval start_thinking = start_time[id]; // Obtenha o tempo de início de pensamento
        // Converter o tempo atual em milissegundos
        long long current_time = current_time_ms();
        printf("%lldms %d is thinking\n", current_time - timeval_to_milliseconds(start_thinking), id);
        // Registrar o tempo da última refeição
        struct timeval last_meal;
        gettimeofday(&last_meal, NULL);
        // Pegar garfos
        pthread_mutex_lock(&forks[left_fork]);
        pthread_mutex_lock(&forks[right_fork]);
        // Comer
        printf("%lldms %d is eating\n", current_time - timeval_to_milliseconds(start_thinking), id);
        usleep(time_to_eat * 1000); // Convertendo para microssegundos
        // Liberar garfos
        pthread_mutex_unlock(&forks[left_fork]);
        pthread_mutex_unlock(&forks[right_fork]);
        // Dormir
        struct timeval start_sleeping = last_meal;
        printf("%lldms %d is sleeping\n", current_time - timeval_to_milliseconds(start_thinking), id);
        usleep(time_to_sleep * 1000); // Convertendo para microssegundos
    }

    return NULL;
}

void *observe(void *arg) {
    while (1) {
        usleep(5); // Verificar a cada 5ms segundo

        for (int i = 0; i < num_philosophers; i++) {
            long long current_time = current_time_ms();
            if (time_diff_in_ms(timeval_to_milliseconds(start_time[i]), current_time) > time_to_die * 1000LL) { // Convertendo para milissegundos
                printf("%d has died\n", i);
                exit(1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Uso: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 1;
    }

    num_philosophers = atoi(argv[1]);
    time_to_die = atoi(argv[2]);
    time_to_eat = atoi(argv[3]);
    time_to_sleep = atoi(argv[4]);
    num_times_each_philosopher_must_eat = (argc == 6) ? atoi(argv[5]) : 0;

    if (num_philosophers < 2 || num_philosophers > MAX_PHILOSOPHERS) {
        printf("O número de filósofos deve estar entre 2 e %d\n", MAX_PHILOSOPHERS);
        return 1;
    }

    // Inicializar os garfos
    for (int i = 0; i < num_philosophers; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Inicializar o registro de tempo desde o início do programa
    start_time = malloc(sizeof(struct timeval) * num_philosophers);
    for (int i = 0; i < num_philosophers; i++) {
        gettimeofday(&start_time[i], NULL);
    }

    // Criar filósofos
    for (int i = 0; i < num_philosophers; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&philosophers[i], NULL, philosopher, id);
    }

    // Criar o observador
    pthread_create(&observer, NULL, observe, NULL);

    //
    // Aguardar filósofos terminarem
    for (int i = 0; i < num_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destruir garfos
    for (int i = 0; i < num_philosophers; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    // Liberar a memória do registro de tempo desde o início do programa
    free(start_time);

    return 0;
}
