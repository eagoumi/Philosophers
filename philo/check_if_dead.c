/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:54:30 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 16:40:04 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	norm_dead(t_philo *philo)
{
	long	get_time;

	pthread_mutex_lock(&philo->output);
	get_time = (current_time() - philo->args->time_start);
	printf("Philosopher %d is dead at --------- %ld\n",
		philo->philo_id, get_time);
	philo->args->are_dead = 1;
}

int	if_dead(t_philo *philo)
{
	long	time;

	time = current_time() - philo->dernier_repas;
	if (time > philo->args->time_to_die)
	{
		norm_dead(philo);
		return (1);
	}
	return (0);
}

int	check_if_dead(t_alldata *allinfo)
{
	int	i;
	int	count_nb_of_meals;

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
