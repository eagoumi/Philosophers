 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/23 02:26:58 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_fork(t_philo *philos)
{
	pthread_mutex_lock(&philos->fork_left);
	pthread_mutex_lock(&philos->fork_right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(&philo->fork_right);
}



long    current_time(void)
{
    struct timeval gettime;
    long    milli_time;

    gettimeofday(&gettime, NULL);

    /*convert Microseconds to Milliseconds*/
    milli_time = (gettime.tv_sec * 1000) + (gettime.tv_usec / 1000);
    return (milli_time);
}

void    mine_sleep(long time)
{
    long    begin_time;
    long    the_passed_time;

    begin_time = current_time();
    the_passed_time = current_time() + time;

    while (the_passed_time > begin_time)
    {
        usleep(100);
        begin_time = current_time();
    }
}


void    check_if_dead()
{

}


void    routine_philos(void *arg);
void *philosophers_threads(void *arg) 
{
    t_philo *data = (t_philo *)arg;

    while (1)
	{
        printf("Philosopher %d is thinking \n", data->philo_id);
        mine_sleep(100);
		
		grab_fork(data);
		
        printf("Philosopher %d is eating\n", data->philo_id);
        //if
        mine_sleep(100);

		release_forks(data);
		
        printf("Philosopher %d is Sleeping\n", data->philo_id);
        mine_sleep(100);
    }
    printf("Philosopher %d has finished eating\n", data->philo_id);
    return NULL;
}

int main(int ac, char **av) {
    t_info get_data;
    t_philo *data;
    pthread_t *threads;
    int number_philos;
    int i;

    if (ac < 5 || ac > 6)
        return 0;

    number_philos = atoi(av[1]);
    // Allocate memory for data and threads arrays
    data = (t_philo *)malloc(sizeof(t_philo) * number_philos);
    threads = (pthread_t *)malloc(sizeof(pthread_t) * number_philos);

    // Initialize data[i].args members
    get_data.number_philos = atoi(av[1]);
    get_data.time_to_die = atoi(av[2]);
    get_data.time_to_eat = atoi(av[3]);
    get_data.time_to_sleep = atoi(av[4]);
    if (ac == 6)
        get_data.number_ropas = atoi(av[5]);

    i = 0;
    while (i < number_philos) 
    {
        data[i].philo_id = i;
        data[i].args = &get_data; // Set the pointer to the shared t_info struct
        pthread_create(&threads[i], NULL, philosophers_threads, &data[i]);
        i += 2;
    }
    mine_sleep(get_data.time_to_eat/2);
    i = 1;
    while (i < number_philos)
    {
        data[i].philo_id = i;
        data[i].args = &get_data; // Set the pointer to the shared t_info struct
        pthread_create(&threads[i], NULL, philosophers_threads, &data[i]);
        i += 2;
    }

    i = 0;
    /* Wait for all threads to finish before exiting */
    while (i < number_philos) 
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    /* Don't forget to free allocated memory before exiting */
    free(data);
    free(threads);

    return 0;
}

