#include "philosophers_bonus.h"

void    routine_philos(t_philo *data)
{
    pthread_t   thread;

    data->args->time_start = current_time();
    data->dernier_repas = current_time();
    pthread_create(&thread, NULL, check_if_death, (void *)data);

    while (1)
    {
        if (data->eaten_time != 0)
        {
            sem_wait(data->sema->forks);
            printf("%ld --------- Philosopher %d has taken the FORK\n", (current_time() - data->args->time_start) ,data->philo_id);
            printf("%ld --------- Philosopher %d is EATING\n", (current_time() - data->args->time_start), data->philo_id);
            data->dernier_repas = current_time();
            mine_sleep(data->args->time_to_eat);
            sem_post(data->sema->forks);
            data->eaten_time--;
            printf("%ld --------- Philosopher %d is SLEEPING\n", (current_time() - data->args->time_start), data->philo_id);
            mine_sleep(data->args->time_to_sleep);
            printf("%ld --------- Philosopher %d is THINKING\n", (current_time() - data->args->time_start), data->philo_id);
        }
        else
        {
            pthread_join(thread, NULL);
            return ;
        }
    }
}
