/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:37:59 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/25 09:25:00 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initial_philo(t_alldata *get_info)
{
	int	i;

	i = 0;
	get_info->philo = (char *)malloc(sizeof(t_philo) * get_info->philo->number_philos);
	if (!get_info->philo)
		return (1);
	while (i < get_info->philo->number_philos)
	{
		get_info->philo[i].philo_id = i + 1;
		get_info->philo[i].dernier_repas = 0;
		get_info->philo[i].eaten_time = get_info->philo->number_ropas;
		get_info->philo[i].args = get_info->philo;
		get_info->philo[i].mtx = get_info->key_to;
		get_info->philo[i].right_fork = &get_info->key_to->forks[i];
		if ((i + 1) == get_info->philo->number_philos)
			get_info->philo[i].left_fork = &get_info->key_to->forks[0];
		else
			get_info->philo[i].left_fork = &get_info->key_to->forks[i + 1];
		i++;
	}
	return (0);
}
