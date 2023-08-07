#include "philosophers.h"

int initial_mtx(t_alldata *get_info)
{
    int i;

    i = 0;
    get_info->key_to = (t_mtx *)malloc(sizeof(t_mtx));
    if (!get_info->key_to)
        return (1);
    get_info->key_to->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * get_info->philo->number_philos);
    if (!get_info->key_to->forks)
        return (1);
    while (i < get_info->philo->number_philos)
    {
        if (pthread_mutex_init(&get_info->key_to->forks[i], NULL) != 0)
            return (1);
        i++;
    }
    return (0);
    
}