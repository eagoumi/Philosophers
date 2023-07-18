/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/18 04:38:21 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_id(void *arg)
{
	sleep(1);
	printf("philo %d is \n", (int) arg);
	return NULL;
}

int	main(int ac, char **av)
{
	t_info	get_data;
	t_philo	create_thread;
	int philo_idi;
	int		i;

	i = 0;
	if (ac != 6)
		return (0);
	// parsing(ac, av);
	get_data.number_philos = atoi (av[1]);
	get_data.time_to_die = atoi (av[2]);
	get_data.time_to_eat = atoi (av[3]);
	get_data.time_to_sleep = atoi (av[4]);
	get_data.number_ropas = atoi (av[5]);
	while (i < get_data.number_philos)
	{
		pthread_create(&create_thread.thread, NULL, philo_id, NULL);
		pthread_join(create_thread.thread, NULL);
		i++;
	}
}
