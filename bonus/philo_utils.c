/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:51:32 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 15:51:47 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	wait_for_loop(t_alldata *alldata)
{
	int	i;
	int	j;
	int	stat;

	i = 0;
	waitpid(-1, &stat, 0);
	while (i < alldata->info->number_philos)
	{
		if (stat == 0)
		{
			j = 0;
			while (j < alldata->info->number_philos)
			{
				kill(alldata->philo->pid[j], SIGTERM);
				j++;
			}
		}
		i++;
	}
}

int	initial_pross(t_alldata *alldata)
{
	int	i;
	int	j;
	int	stat;

	i = 0;
	while (i < alldata->info->number_philos)
	{
		alldata->philo->pid[i] = fork();
		if (alldata->philo->pid[i] == 0)
		{
			alldata->philo->philo_id = i + 1;
			routine_philos(alldata->philo);
		}
		else if (alldata->philo->pid[i] == -1)
			return (1);
		i++;
	}
	wait_for_loop(alldata);
	return (0);
}
