/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 06:26:47 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/14 06:34:45 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	create_threats(int ac, char **av)
{
	int	i;
	pthread_t mutex;

	while (av[1])
	{
		i = atoi(av[i]);
		pthread_create();

	}
}