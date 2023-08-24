/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:09:17 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 20:39:39 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	x;
	int	signe;

	signe = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\n' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		signe = signe * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	x = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		x = (x * 10) + (str[i] - 48);
		i++;
	}
	return (signe * x);
}

int	main(int ac, char **av)
{
	t_alldata	get_data;
	t_info		data;

	get_data.info = &data;
	if (ac < 5 || ac > 6)
	{
		printf("Error //!\\\\ Too few ARGUMENTS in Philo\n");
		return (0);
	}
	if (parsing(av))
		return (0);
	get_data.info->number_philos = ft_atoi(av[1]);
	get_data.info->time_to_die = ft_atoi(av[2]);
	get_data.info->time_to_eat = ft_atoi(av[3]);
	get_data.info->time_to_sleep = ft_atoi(av[4]);
	get_data.info->number_ropas = -1;
	get_data.info->is_dead = 0;
	if (ac == 6)
		get_data.info->number_ropas = ft_atoi(av[5]);
	if (initial_mtx(&get_data))
		return (0);
	if (initial_philo(&get_data))
		return (0);
	if (final_philo(&get_data))
		return (0);
}
