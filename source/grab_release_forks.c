#include "philosophers.h"

void	grab_fork_left(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_left);
}

void	grab_fork_right(t_philo *philos)
{
	pthread_mutex_lock(philos->fork_right);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}
