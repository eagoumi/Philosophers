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
			printf("Parsing ERROR an argument start with '\\0'\n");
			return (1);
		}
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Parsing_Bonus ERROR\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
