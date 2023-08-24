/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:09:17 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 16:10:02 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_alldata	get_data;
	t_info		data;

	get_data.info = &data;
	if (ac < 5 || ac > 6)
		return (0);
	if (parsing(ac, av))
		return (0);
	get_data.info->number_philos = atoi(av[1]);
	get_data.info->time_to_die = atoi(av[2]);
	get_data.info->time_to_eat = atoi(av[3]);
	get_data.info->time_to_sleep = atoi(av[4]);
	get_data.info->number_ropas = -1;
	get_data.info->is_dead = 0;
	if (ac == 6)
		get_data.info->number_ropas = atoi(av[5]);
	if (initial_mtx(&get_data))
		return (0);
	if (initial_philo(&get_data))
		return (0);
	if (final_philo(&get_data))
		return (0);
	return (0);
}
