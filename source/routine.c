#include "philosophers.h"

void    routine_philos(t_philo *data)
{
    grab_fork_right(data);
    printf("%ld --------- Philosopher %d has taken the RIGHT FORK\n", (current_time() - data->args->time_start) ,data->philo_id);
    grab_fork_left(data);
    printf("%ld --------- Philosopher %d has taken the LEFT FORK\n", (current_time() - data->args->time_start), data->philo_id);
    printf("%ld --------- Philosopher %d is EATING\n", (current_time() - data->args->time_start), data->philo_id);
    data->dernier_repas = current_time();
    mine_sleep(data->args->time_to_eat);
    release_forks(data);
    data->eaten_time--;
    printf("%ld --------- Philosopher %d is SLEEPING\n", (current_time() - data->args->time_start), data->philo_id);
    mine_sleep(data->args->time_to_sleep);
    printf("%ld --------- Philosopher %d is THINKING\n", (current_time() - data->args->time_start), data->philo_id);

}

void    *routine_philo_main(void *args)
{
    t_philo *data = (t_philo *)args;
    data->dernier_repas = current_time();
    while (1)
    {
        if(data->eaten_time != 0)
            routine_philos(data);
        else
            break ;
    }
    return (NULL);
}
