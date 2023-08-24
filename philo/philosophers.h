/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:42:03 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 18:22:01 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <libc.h>
# include <ctype.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct mtxx_s
{
	pthread_mutex_t	*forks;
}	t_mtx;

typedef struct philoinfo_s
{
	long	time_start;
	int		number_philos;
	int		number_ropas;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		is_dead;
	int		are_dead;

}	t_info;

typedef struct philo_s
{
	int				philo_id;
	int				eaten_time;
	long			dernier_repas;
	t_mtx			*mtx;
	pthread_t		threads;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	output;
	t_info			*args;
}	t_philo;

typedef struct alldata_s
{
	t_philo	*philo;
	t_info	*info;
	t_mtx	*key_to;

}	t_alldata;

int		parsing(char **av);
int		if_dead(t_philo *philo);
int		check_if_dead(t_alldata *allinfo);
int		create_philo(t_alldata *get_philo, int j, int i);
int		final_philo(t_alldata *get_philo);
void	grab_fork_left(t_philo *philos);
void	grab_fork_right(t_philo *philos);
void	release_forks(t_philo *philo);
int		initial_mtx(t_alldata *get_info);
int		initial_philo(t_alldata *get_info);
long	current_time(void);
void	mine_sleep(long time);
void	*routine_philo_main(void *args);
void	routine_philos(t_philo *data);

#endif