/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 10:43:36 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/26 14:37:27 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <libc.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct semaphore_s
{
	sem_t	*forks;
	sem_t	*mutex;
	sem_t	*out_put;
}	t_semaphore;

typedef struct info_s
{
	long	time_start;
	int		number_philos;
	int		number_ropas;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		is_dead;
}	t_info;

typedef struct philo_s
{
	int			philo_id;
	int			eaten_time;
	long		dernier_repas;
	pid_t		*pid;
	t_info		*args;
	t_semaphore	*sema;
}	t_philo;

typedef struct alldata_s
{
	t_semaphore	*key;
	t_philo		*philo;
	t_info		*info;
}	t_alldata;

void	*check_if_death(void *check);
void	*ft_malloc(size_t size);
int		ft_pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
			void *(*start_routine)(void *), void *arg);
int		ft_sem_close(sem_t *sem);
int		ft_sem_wait(sem_t *sem);
int		ft_sem_post(sem_t *sem);
int		ft_kill(pid_t pid, int sig);
int		ft_gettimeofday(struct timeval *restrict tp, void *restrict tzp);
int		ft_pthread_join(pthread_t thread, void **value_ptr);
void	mine_sleep(long time);
long	current_time(void);
void	wait_for_loop(t_alldata *alldata);
void	routine_philos(t_philo *data);
int		initial_pross(t_alldata *alldata);
int		initial_semaphore(t_alldata *getinfo);
int		initial_philo(t_alldata *getinfo);
void	my_free_sem(t_alldata *alldata);
int		parsing(char **av);

#endif