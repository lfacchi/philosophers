#include "philo.h"

long long     current_time_ms() {
    struct      timeval tv;
    long long   current;

    gettimeofday(&tv, NULL);
    current = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
    return current;
}

long long time_diff_in_ms(long long start, long long end) {
    long long result;
    result = end - start;
    return result;
}

long long time_on_app(t_table *table)
{
    long long result;
    result = time_diff_in_ms(table->start_time, current_time_ms());
    return result;
}