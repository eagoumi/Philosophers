/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:12:09 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 16:37:03 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	join(pthread_t thread)
{
	ft_pthread_join(thread, NULL);
}

void	print_eating_time(t_philo *data)
{
	printf("\x1B[1;31m=======> PHILOSOPHER \x1B[1;33m%d \x1B[1;33mis\
 EATING \x1B[1;31mfor the \x1B[1;33m%d \x1B[1;31m\
TIME <======= \x1b[37m\n", data->philo_id, 
		(data->args->number_ropas + 1 - data->eaten_time));
}

void	print_take_fork(t_philo *data, char *str)
{
	ft_sem_wait(data->sema->out_put);
	if (data->args->is_dead == 0)
		printf("%ld --------- Philosopher %d %s\n", 
			(current_time() - data->args->time_start), data->philo_id, str);
	ft_sem_post(data->sema->out_put);
}

void	norm_rotine(t_philo *data)
{
	ft_sem_wait(data->sema->forks);
	print_take_fork(data, "\x1B[1;34mhas taken the FORK\x1b[37m");
	data->dernier_repas = current_time();
	print_take_fork(data, "\x1B[1;32mis EATING");
	print_eating_time(data);
	mine_sleep(data->args->time_to_eat);
	ft_sem_post(data->sema->forks);
	ft_sem_post(data->sema->forks);
	data->eaten_time--;
	print_take_fork(data, "is SLEEPING");
	mine_sleep(data->args->time_to_sleep);
	print_take_fork(data, "is THINKING");
}

void	routine_philos(t_philo *data)
{
	pthread_t	thread;

	data->args->time_start = current_time();
	data->dernier_repas = current_time();
	ft_pthread_create(&thread, NULL, check_if_death, (void *)data);
	while (1)
	{
		if (data->eaten_time != 0)
			norm_rotine(data);
		else
			return (join(thread));
	}
}
