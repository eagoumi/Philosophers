/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:52:00 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 15:53:47 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_alldata	get_data;
	t_info		data;

	get_data.info = &data;
	if (argc < 5 || argc > 6)
		return (1);
	if (parsing(argv))
		return (0);
	get_data.info->number_philos = atoi(argv[1]);
	get_data.info->time_to_die = atoi(argv[2]);
	get_data.info->time_to_eat = atoi(argv[3]);
	get_data.info->time_to_sleep = atoi(argv[4]);
	get_data.info->number_ropas = -1;
	get_data.info->is_dead = 0;
	if (argc == 6)
		get_data.info->number_ropas = atoi(argv[5]);
	if (initial_semaphore(&get_data))
		return (0);
	if (initial_philo(&get_data))
		return (0);
	if (initial_pross(&get_data))
		return (0);
	my_free_sem(&get_data);
}
