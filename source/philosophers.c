/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/22 05:49:05 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*philosophers_treads(void *arg)
// {
// 	t_philo *data = (t_philo *)arg;
// 	int i;

// 	while (1)
// 	{
// 		// data->philo_id = i;
// 		puts("ss");
// 		printf("Philosophers %d is thinking\n", data->philo_id);
// 		sleep(1);
// 		// data->philo_id++;
// 		// i++;
// 	}
// 	return NULL;
// }

// int	main(int ac, char **av)
// {
// 	t_info	get_data;
// 	t_philo	*data;
// 	pthread_mutex_t	*fork;
// 	int		i;

// 	i = 0;
// 	if (ac != 6)
// 		return (0);
// 	// parsing(ac, av);
// 	printf("%d\n", data[i].args->number_philos);
// 	data[i].args->number_philos = atoi (av[1]);
// 	data[i].args->time_to_die = atoi (av[2]);
// 	data[i].args->time_to_eat = atoi (av[3]);
// 	data[i].args->time_to_sleep = atoi (av[4]);
// 	data[i].args->number_ropas = atoi (av[5]);

// 	exit(1);

// 	while (i < data[i].args->number_philos)
// 	{
// 		data[i].philo_id = i;
// 		pthread_create(&data[i].thread, NULL, philosophers_treads, NULL);
// 		pthread_join(data[i].thread, NULL);
// 		i++;
// 	}

// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>

// typedef struct {
//     int number_philos;
//     int time_to_die;
//     int time_to_eat;
//     int time_to_sleep;
//     int number_ropas;
// } t_info;

// typedef struct {
//     int philo_id;
//     pthread_t thread;
//     t_info *args; // Pointer to the shared t_info struct
// } t_philo;
void	grab_fork(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_left);
	pthread_mutex_lock(philos->fork_right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void *philosophers_threads(void *arg) {
    t_philo *data = (t_philo *)arg;

    while (1)
	{
        printf("Philosopher %d is thinking\n", data->philo_id);
        sleep(10);
		
		grab_fork(data);
		
        printf("Philosopher %d is eating\n", data->philo_id);
        sleep(10);

		release_forks(data);
		
        printf("Philosopher %d is Sleeping\n", data->philo_id);
        sleep(10);
    }
    printf("Philosopher %d has finished eating\n", data->philo_id);
    return NULL;
}

int main(int ac, char **av) {
    t_info get_data;
    t_philo *data;
    pthread_t *threads;
    int i;

    if (ac != 6) {
        return 1;
    }

    int number_philos = atoi(av[1]);

    // Allocate memory for data and threads arrays
    data = (t_philo *)malloc(sizeof(t_philo) * number_philos);
    threads = (pthread_t *)malloc(sizeof(pthread_t) * number_philos);

    // Initialize data[i].args members
    get_data.number_philos = atoi(av[1]);
    get_data.time_to_die = atoi(av[2]);
    get_data.time_to_eat = atoi(av[3]);
    get_data.time_to_sleep = atoi(av[4]);
    get_data.number_ropas = atoi(av[5]);

    for (i = 0; i < number_philos; i++) {
        data[i].philo_id = i;
        data[i].args = &get_data; // Set the pointer to the shared t_info struct
        pthread_create(&threads[i], NULL, philosophers_threads, &data[i]);
    }

    // Wait for all threads to finish before exiting
    for (i = 0; i < number_philos; i++) {
        pthread_join(threads[i], NULL);
    }

    // Don't forget to free allocated memory before exiting
    free(data);
    free(threads);

    return 0;
}

