/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/21 17:18:29 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosophers_treads(void *arg)
{
	t_philo	*data = (t_philo *)arg;
	
	puts("ss");
	printf("%d\n", data->data->args->time_to_eat);
	while (data->eaten_time < data->args->time_to_eat)
	{
		printf("agoumi");
		data->eaten_time++;
	}
	// sleep(1);
	// printf("philo %d is \n", (int) arg);
	return NULL;
}

int	main(int ac, char **av)
{
	t_info	get_data;
	t_philo	create_thread;
	pthread_mutex_t	*fork;
	int philo_idi;
	int		i;

	i = 0;
	if (ac != 6)
		return (0);
	// parsing(ac, av);
	get_data.number_philos = atoi (av[1]);
	get_data.time_to_die = atoi (av[2]);
	get_data.time_to_eat = atoi (av[3]);
	// printf("%d\n", get_data.time_to_eat);
	get_data.time_to_sleep = atoi (av[4]);
	get_data.number_ropas = atoi (av[5]);


	/*Create philosopher threads*/
	while (i < get_data.number_philos)
	{
		pthread_create(&create_thread.thread, NULL, philosophers_treads, NULL);
		pthread_join(create_thread.thread, NULL);
		i++;
	}
	
	/*Wait for philosopher threads to finish*/
	// while (i < get_data.number_philos)
	// {
	// 	pthread_join(create_thread.thread, NULL);
	// 	i++;
	// }
}
