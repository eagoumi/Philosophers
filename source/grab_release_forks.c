/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:58:04 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 15:58:06 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_fork_left(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_left);
}

void	grab_fork_right(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
