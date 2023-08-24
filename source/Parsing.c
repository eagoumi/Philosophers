/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 05:58:19 by eagoumi           #+#    #+#             */
/*   Updated: 2023/08/24 17:40:22 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing(char **av)
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
				puts("Parsing error");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
