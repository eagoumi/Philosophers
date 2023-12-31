/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:58:19 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/25 12:18:27 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_isdigit(int st)
{
	return (st >= '0' && st <= '9');
}

int	parsing(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (!(av[i][0]))
		{
			write(2, "Parsing ERROR an argument start with '\\0'\n", 42);
			exit (1);
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				write(2, "Parsing_Bonus ERROR\n", 20);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
