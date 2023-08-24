/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:58:15 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 18:29:51 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initial_mtx(t_alldata *get_info)
{
	int	i;

	i = 0;
	get_info->key_to = (t_mtx *)malloc(sizeof(t_mtx));
	if (!get_info->key_to)
	{
		printf("ERROR in Allocation MUTEX\n");
		return (1);
	}
	get_info->key_to->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * get_info->info->number_philos);
	if (!get_info->key_to->forks)
	{
		printf("ERROR in Allocation FORKS\n");
		return (1);
	}
	while (i < get_info->info->number_philos)
	{
		if (pthread_mutex_init(&get_info->key_to->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
