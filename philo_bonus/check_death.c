/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:49:58 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 17:00:23 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*check_if_death(void *check)
{
	long	time;
	t_philo	*philo;

	philo = (t_philo *) check;
	while (1)
	{
		time = current_time() - (philo->dernier_repas);
		if (time > philo->args->time_to_die)
		{
			ft_sem_wait(philo->sema->out_put);
			printf("Philosopher : Nº •••%d••• is dead on : %ld\n", 
				philo->philo_id, (current_time() - philo->args->time_start));
			exit (0);
		}
		if (philo->eaten_time == 0)
		{
			ft_sem_wait(philo->sema->out_put);
			exit (0);
		}
		usleep(100000);
	}
}
