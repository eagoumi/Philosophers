#include "philosophers.h"


int create_philo(t_alldata *get_philo, int j, int i)
{
    if (get_philo->philo[i].philo_id % 2 == j)
    {
        if (pthread_create(&get_philo->philo[i].threads, NULL, &routine_philo_main, &get_philo->philo[i]) != 0)
        {
            free(get_philo->key_to);
            free(get_philo->key_to->forks);
            return (1);
        }
    }
    usleep(300);
    return (0);
}

int final_philo(t_alldata *get_philo)
{
    int i;

    i = -1;
    get_philo->info->time_start = current_time();
    while (++i < get_philo->info->number_philos)
        create_philo(get_philo, 0, i);
    i = -1;
    while (++i < get_philo->info->number_philos)
        create_philo(get_philo, 1, i);
    if (check_if_dead(get_philo))
        return (0);
    i = -1;
    while (++i < get_philo->info->number_philos)
    {
        if (pthread_join(get_philo->philo[i].threads, NULL) != 0)
        {
            /*handle if join return error*/
            printf("Error joining thread\n");
            return (1);
        }
    }
    return (0);
}
