/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:37:59 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/25 09:25:00 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosophers.h"

// #include <libc.h>

void *actions (void *arg)
{
	sleep(1);
	puts("threads");
	return NULL;
}

void	create_philo(void)
{
	t_philo	mythread;
	t_philo	mythread1;

	pthread_create(&mythread.thread, NULL, actions, NULL);
	pthread_create(&mythread1.thread, NULL, actions, NULL);
	// pthread_create(&mythread5.thread, NULL, actions, NULL);
	// pthread_create(&mythread6.thread, NULL, actions, NULL);
	pthread_join(mythread.thread, NULL);

}

int main(void)
{
	create_philo();
}
