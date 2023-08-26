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
	ft_pthread_join(thread, NULL);
}

void	print_take_fork(t_philo *data, char *str)
{
	ft_sem_wait(data->sema->out_put);
	if (data->args->is_dead == 0)
		printf("%ld --------- Philosopher %d %s\n", 
			(current_time() - data->args->time_start), data->philo_id, str);
	ft_sem_post(data->sema->out_put);
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
		{
			ft_sem_wait(data->sema->forks);
			print_take_fork(data, "has taken the FORK");
			data->dernier_repas = current_time();
			print_take_fork(data, "is EATING");
			printf("=======> Philosopher %d is eating for the %d time <======= \n", data->philo_id, (data->args->number_ropas + 1 - data->eaten_time));
			mine_sleep(data->args->time_to_eat);
			ft_sem_post(data->sema->forks);
			ft_sem_post(data->sema->forks);
			data->eaten_time--;
			print_take_fork(data, "is SLEEPING");
			mine_sleep(data->args->time_to_sleep);
			print_take_fork(data, "is THINKING");
		}
		else
			return (join(thread));
	}
}
