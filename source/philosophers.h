/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:42:03 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/24 08:09:14 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
# include <pthread.h>
# include <sys/time.h>

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
	int				philo_id;
	int				eaten_time;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	t_info			*args;
	
}	t_philo;

typedef struct alldata_s
{
	t_philo	*philo;
	t_info	*info;

}	t_alldata;

void	parsing(int ac, char **av);


#endif