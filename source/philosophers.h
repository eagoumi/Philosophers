/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:42:03 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/18 02:42:12 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
#include <pthread.h>

typedef struct philoinfo_s
{
	int	number_philos;
	int	number_ropas;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

}	t_info;

typedef struct philo_s
{
	pthread_t		thread;
	
}	t_philo;

void	parsing(int ac, char **av);


#endif