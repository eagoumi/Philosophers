/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:12:09 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 16:48:47 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	join(pthread_t thread)
{
	pthread_join(thread, NULL);
	return ;
}

void	print_take_fork(t_philo *data, char *str)
{
	printf("%ld --------- Philosopher %d %s\n", 
		(current_time() - data->args->time_start), data->philo_id, str);
}

void	routine_philos(t_philo *data)
{
	pthread_t	thread;

	data->args->time_start = current_time();
	data->dernier_repas = current_time();
	pthread_create(&thread, NULL, check_if_death, (void *)data);
	while (1)
	{
		if (data->eaten_time != 0)
		{
			sem_wait(data->sema->forks);
			print_take_fork(data, "has taken the FORK");
			print_take_fork(data, "is EATING");
			data->dernier_repas = current_time();
			mine_sleep(data->args->time_to_eat);
			sem_post(data->sema->forks);
			data->eaten_time--;
			print_take_fork(data, "is SLEEPING");
			mine_sleep(data->args->time_to_sleep);
			print_take_fork(data, "is THINKING");
		}
		else
			join(thread);
	}
}
