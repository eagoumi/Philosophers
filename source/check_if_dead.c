#include "philosophers.h"

int if_dead(t_philo *philo)
{
    long    time;
    long    get_time;

    time = current_time() - philo->dernier_repas;
    if (time > philo->args->time_to_die)
    {
        pthread_mutex_lock(&philo->output);
        get_time = (current_time() - philo->args->time_start);
        printf("Philosopher %d is dead at --------- %ld\n",philo->philo_id, get_time);
        philo->args->are_dead = 1;
        return (1);
    }
    return (0);
}

int check_if_dead(t_alldata *allinfo)
{
    int i;
    int count_nb_of_meals;
    while (1)
    {
        i = 0;
        count_nb_of_meals = 0;
        while (i < allinfo->info->number_philos)
        {
            if (if_dead(&allinfo->philo[i]))
                return (1);
            count_nb_of_meals += allinfo->philo[i].eaten_time;
            i++;
            if (count_nb_of_meals == 0)
            {
                pthread_mutex_lock(&allinfo->philo->output);
                return (1);
            }
        }
    }
    return (0);
}
