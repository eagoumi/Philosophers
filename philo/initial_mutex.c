/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:58:15 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 16:44:01 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	initial_mtx(t_alldata *get_info)
{
	int	i;

	i = 0;
	get_info->key_to = (t_mtx *)ft_malloc(sizeof(t_mtx));
	get_info->key_to->forks = (pthread_mutex_t *)ft_malloc(
			sizeof(pthread_mutex_t) * get_info->info->number_philos);
	while (i < get_info->info->number_philos)
	{
		if (pthread_mutex_init(&get_info->key_to->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
