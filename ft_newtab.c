/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:09:33 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:31:18 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_getnb(char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i] == '#')
			j++;
		i++;
	}
	return (j / 4);
}

int		ft_tabid(int nb)
{
	int	i;

	i = 1;
	nb = nb * 4;
	while ((i * i) < nb)
		i++;
	return (i);
}

char	**ft_newtab(int i, char **table)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < i)
	{
		if ((table[y] = (char *)malloc(sizeof(char *) * (i + 1))) == 0)
			return (NULL);
		while (x < i)
		{
			table[y][x] = '.';
			x++;
		}
		table[y][x] = '\0';
		x = 0;
		y++;
	}
	table[y] = NULL;
	return (table);
}
