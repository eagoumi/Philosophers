/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_currtime_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:11:01 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 16:11:54 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long	current_time(void)
{
	struct timeval	gettime;
	long			milli_time;

	ft_gettimeofday(&gettime, NULL);
	milli_time = (gettime.tv_sec * 1000) + (gettime.tv_usec / 1000);
	return (milli_time);
}

void	mine_sleep(long time)
{
	long	begin_time;
	long	the_passed_time;

	begin_time = current_time();
	the_passed_time = current_time() + time;
	while (the_passed_time > begin_time)
	{
		usleep(100);
		begin_time = current_time();
	}
}
