/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_sems_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:50:20 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 15:57:40 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	initial_semaphore(t_alldata *getinfo)
{
	getinfo->key = ft_malloc(sizeof(t_semaphore));
	sem_unlink("out_put");
	getinfo->key->out_put = sem_open("out_put", O_CREAT, 777, 1);
	if (getinfo->key->out_put == SEM_FAILED)
		return (1);
	sem_unlink("forks");
	getinfo->key->forks = sem_open("forks", O_CREAT, 777, 
			(getinfo->info->number_philos / 2));
	if (getinfo->key->forks == SEM_FAILED)
		return (1);
	return (0);
}

int	initial_philo(t_alldata *getinfo)
{
	int	i;

	i = 0;
	getinfo->philo = ft_malloc(sizeof(t_philo) * getinfo->info->number_philos);
	getinfo->philo->pid = ft_malloc(sizeof(pid_t) * 
			getinfo->info->number_philos);
	getinfo->info->is_dead = 0;
	getinfo->philo->eaten_time = getinfo->info->number_ropas;
	getinfo->philo->args = getinfo->info;
	getinfo->philo->sema = getinfo->key;
	return (0);
}

void	my_free_sem(t_alldata *alldata)
{
	sem_unlink("out_put");
	sem_unlink("forks");
	sem_close(alldata->key->out_put);
	sem_close(alldata->key->forks);
}
