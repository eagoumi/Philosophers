/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:52:00 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 16:00:54 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	x;

	i = 0;
	x = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (x >= INT_MAX)
		{
			write(2, "too high VALUE\n", 15);
			exit (1);
		}
		x = (x * 10) + (str[i] - 48);
		i++;
	}
	if (x >= INT_MAX)
	{
		write(2, "too high VALUE\n", 15);
		exit (1);
	}
	return (x);
}

void	norm(t_alldata get_data, char **argv)
{
	get_data.info->number_philos = ft_atoi(argv[1]);
	get_data.info->time_to_die = ft_atoi(argv[2]);
	get_data.info->time_to_eat = ft_atoi(argv[3]);
	get_data.info->time_to_sleep = ft_atoi(argv[4]);
	get_data.info->number_ropas = -1;
	get_data.info->is_dead = 0;
}

int	main(int argc, char **argv)
{
	t_alldata	get_data;
	t_info		data;

	get_data.info = &data;
	if (argc < 5 || argc > 6)
	{
		printf("Error //!\\\\ Too few ARGUMENTS in PHILO_BONUS\n");
		return (1);
	}
	if (parsing(argv))
		return (0);
	norm(get_data, argv);
	if (argc == 6)
		get_data.info->number_ropas = ft_atoi(argv[5]);
	if (initial_semaphore(&get_data))
		return (1);
	initial_philo(&get_data);
	if (initial_pross(&get_data))
		return (0);
	my_free_sem(&get_data);
	free(get_data.key);
	free(get_data.philo->pid);
	free(get_data.philo);
}
