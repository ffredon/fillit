/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolstab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:10:14 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:31:57 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_str(char **tab, char *str, int x, int y)
{
	int		i;

	i = 0;
	while (tab[y][x])
	{
		str[i] = tab[y][x];
		x++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_piece(char **tab, int x, int y)
{
	int	count;

	count = 0;
	while (tab[y])
	{
		if (tab[y][x] != '#')
			count++;
		y++;
	}
	if (count == 4)
		return (1);
	return (0);
}

int		ft_srch(char **tab, int x, int y)
{
	int		xmax;

	if (tab[y][x] != '#' && tab[y][x + 1] != '#')
	{
		while (tab[y][x] != '#' && tab[y][x + 1] != '#')
		{
			if (x == 3)
			{
				x = -1;
				y++;
			}
			x++;
		}
	}
	if (ft_piece(tab, x, 0) == 1)
		x++;
	xmax = x;
	return (xmax);
}

int		ft_srch2(char **tab, int x, int y)
{
	int		ymin;

	while (tab[y][x] != '#' && tab[y][x + 1] != '#')
	{
		if (x == 3)
		{
			x = -1;
			y++;
		}
		x++;
	}
	ymin = y;
	return (ymin);
}
