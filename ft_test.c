/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:06:51 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:31:45 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checknorm(char c)
{
	if (c != '#' && c != '.')
		return (0);
	return (1);
}

int		ft_checkn(char c)
{
	if (c != '\n')
		return (0);
	return (1);
}

int		ft_checkend(char *tab, int i, int n)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = i - 20;
	while (i < n)
	{
		if (tab[i] == '#')
		{
			j++;
			if (tab[i - 5] == '#')
				k++;
			if (tab[i - 1] == '#')
				k++;
			if (tab[i + 1] == '#')
				k++;
			if (tab[i + 5] == '#')
				k++;
		}
		i++;
	}
	if (j != 4 || k < 6 || !tab[i + 21])
		return (0);
	return (1);
}

int		ft_checkl(int n)
{
	int		x;
	int		y;

	n = n - 5;
	x = 0;
	y = 19;
	while (n > y)
	{
		x = x + 21;
		y = x + 19;
	}
	if (n != y)
		return (0);
	return (1);
}

int		ft_checkfinal(char *tab, int i, int n)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (ft_checkl(n) == 0)
		return (0);
	return (ft_check3(tab, i, n));
}
