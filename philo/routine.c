/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:02:49 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 16:53:06 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo_rotine(t_philo *data, char *str)
{
	printf("%ld \x1B[1;31m---------\x1b[37m Philosopher \x1B[1;33m%d \x1b[37m%s\n", 
		(current_time() - data->args->time_start), data->philo_id, str);
}

void	routine_philos(t_philo *data)
{
	grab_fork_right(data);
	print_philo_rotine(data, "\x1B[1;31mhas taken the RIGHT FORK\x1b[37m");
	grab_fork_left(data);
	print_philo_rotine(data, "\x1B[1;34mhas taken the LEFT FORK\x1b[37m");
	print_philo_rotine(data, "\x1B[1;32mis EATING\x1b[37m");
	data->dernier_repas = current_time();
	mine_sleep(data->args->time_to_eat);
	release_forks(data);
	data->eaten_time--;
	print_philo_rotine(data, "is SLEEPING");
	mine_sleep(data->args->time_to_sleep);
	print_philo_rotine(data, "is THINKING");
}

void	*routine_philo_main(void *args)
{
	t_philo	*data;

	data = (t_philo *)args;
	data->dernier_repas = current_time();
	while (1)
	{
		if (data->eaten_time != 0)
			routine_philos(data);
		else
			break ;
	}
	return (NULL);
}
