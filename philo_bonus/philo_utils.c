/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:51:32 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 14:38:41 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	kill_all_process(t_alldata *alldata)
{
	int	j;

	j = 0;
	while (j < alldata->info->number_philos)
	{
		kill(alldata->philo->pid[j], SIGTERM);
		j++;
	}
}

void	wait_for_loop(t_alldata *alldata)
{
	int		completed_philo;
	int		stat;
	pid_t	completed_pid;

	completed_philo = 0;
	while (completed_philo < alldata->info->number_philos)
	{
		completed_pid = waitpid(-1, &stat, 0);
		if (completed_pid > 0)
		{
			if (WIFEXITED(stat) && WEXITSTATUS(stat) == 0)
			{
				kill_all_process(alldata);
				break ;
			}
			else if (WIFEXITED(stat) && WEXITSTATUS(stat) == 2)
			{
				completed_philo++;
			}
		}
	}
}

int	initial_pross(t_alldata *alldata)
{
	int	i;

	i = 0;
	while (i < alldata->info->number_philos)
	{
		alldata->philo->pid[i] = fork();
		if (alldata->philo->pid[i] == 0)
		{
			alldata->philo->philo_id = i + 1;
			routine_philos(alldata->philo);
			exit(2);
		}
		else if (alldata->philo->pid[i] == -1)
		{
			kill_all_process(alldata);
			return (1);
		}
		i++;
	}
	wait_for_loop(alldata);
	return (0);
}
