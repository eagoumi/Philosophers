/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:42:03 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/25 05:06:19 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct philoinfo_s
{
	long	time_start;
	int		number_philos;
	int		number_ropas;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;

}	t_info;

typedef struct philo_s
{
	int				philo_id;
	int				eaten_time;
	int				are_dead;
	long			dernier_repas;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*output;
	t_info			*args;
	
}	t_philo;

typedef struct alldata_s
{
	t_philo	*philo;
	t_info	*info;

}	t_alldata;

void	parsing(int ac, char **av);


#endif