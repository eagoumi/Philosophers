#include "philosophers_bonus.h"

void	*check_if_death(void *check)
{
	int		repas_count;
	long	time;
	t_philo	*philo;

	philo = (t_philo *) check;
	while (1)
	{
		repas_count = 0;
		time = current_time() - (philo->dernier_repas);
		if (time > philo->args->time_to_die)
		{
			sem_wait(philo->sema->out_put);
			printf("Philosopher : %d is dead on : %ld", philo->philo_id,(current_time() - philo->args->time_start));
			exit (0);
		}
		repas_count += philo->eaten_time;
		if (repas_count == 0)
		{
			sem_wait(philo->sema->out_put);
			exit (0);
		}
	}
}
