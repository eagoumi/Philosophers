/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:42:43 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/16 05:07:06 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosopher.h"
#include <libc.h>
#include <string.h>

typedef struct myphilo_s
{
	int	number_philos;
	int	number_ropas;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

}	t_philo;

/* ***************************************************
typedef struct mutex                                 |
{                                                    |
	pthread_mutex_t	output;                          |     
	pthread_mutex_t	*forks;                          |     
}					t_mutex;                         |      
													 |
typedef struct data                                  |
{                                                    |
	long	start_time;                              | 
	int		dead;                                    |
	int		nb_of_philo;                             |  
	int		time_to_die;                             |  
	int		time_to_eat;                             |  
	int		time_to_sleep;                           |    
	int		nb_of_meals;                             |  
}			t_data;                                  |
													 |
typedef struct philo                                 |
{													 |
	int				philo_id;                        |       
	int				eat_count;                       |        
	long			last_meal;                       |        
	t_data			*args;                           |    
	t_mutex			*mutex;                          |     
	pthread_t		thread;                          |     
	pthread_mutex_t	*right_fork;                     |         
	pthread_mutex_t	*left_fork;                      |         
}					t_philo;                         |     
													 |
typedef struct all                                   |
{													 |
	t_mutex		*lock;                               |
	t_philo		*philo;                              |
	t_data		*data;                               |
}				t_all;                               | 
******************************************************
*/

//./philo <philo_nb> <time_die> <time_eat> <time_slp> [ <must_eat> ]
/*./philo 4 410 200 200
        +-|---|---|-- philo_nb
          +---|---|-- time_die
              +---|-- time_eat
                  +-- time_slp*/
//**************** Minimum time_die for EVEN philo_nb ****************
//	2 x time_eat + e

//**************** Minimum time_die for ODD philo_nb ****************
/*if time_eat >= time_slp

	3 * time_eat + e

if time_eat < time_slp

	time_eat + time_slp + e*/

int	main(int ac, char **av)
{
	t_philo	get_data;

	if (ac != 6)
		return (0);
	parsing(ac, av);
	get_data.number_philos = atoi (av[1]);
	get_data.time_to_die = atoi (av[2]);
	get_data.time_to_eat = atoi (av[3]);
	get_data.time_to_sleep = atoi (av[4]);
	get_data.number_ropas = atoi (av[5]);
}
