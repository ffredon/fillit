/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 09:22:53 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:31:33 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print(char **table)
{
	int		x;
	int		y;
	char	c;

	x = 0;
	y = 0;
	while (table[y])
	{
		while (table[y][x])
		{
			write(1, &table[y][x], 1);
			x++;
		}
		c = '\n';
		write(1, &c, 1);
		x = 0;
		y++;
	}
	free(table);
}

int		ft_print2(char **tab)
{
	ft_print(tab);
	return (1);
}
