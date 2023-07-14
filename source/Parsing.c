/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:58:19 by eagoumi           #+#    #+#             */
/*   Updated: 2023/07/14 06:23:28 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philosophers.h"
#include <libc.h>
#include <ctype.h>

void	parsing(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!isdigit(av[i][j]))
			{
				puts("error");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 6)
		return (0);
	else
	{
		puts("sss");
		parsing(ac, av);
	}
}
