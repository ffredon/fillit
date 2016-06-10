/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:54:49 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:37:16 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_test3(char *tab, int i)
{
	int		x;

	x = 5;
	while (x)
	{
		if (tab[i - x] == '\n' && tab[(i + 1) - x] == '\n')
			return (0);
		x--;
	}
	return (1);
}

int		ft_test2(char *tab)
{
	int		i;
	int		n;

	i = 0;
	n = 4;
	return (ft_test1(tab, i, n));
}

int		ft_check3(char *tab, int i, int n)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	i = i - 20;
	while (i < n)
	{
		if (tab[i] == '#')
		{
			j++;
			if (tab[i - 5] == '#' && ft_test3(tab, i) == 1)
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
	if (j != 4 || k < 6)
		return (0);
	return (1);
}

int		ft_test1(char *tab, int i, int n)
{
	while (tab[i] && i < 545)
	{
		while (i < n)
		{
			if (ft_checknorm(tab[i]) == 0)
				return (0);
			i++;
		}
		if (ft_checkn(tab[i]) == 0)
			return (0);
		if ((++i + 1) % 21 == 0 && tab[i])
		{
			if (ft_checkn(tab[i]) == 0 || ft_checkend(tab, i, n) == 0)
				return (0);
			n++;
			i++;
		}
		n = n + 5;
	}
	if (ft_checkfinal(tab, i, n) == 0)
		return (0);
	return (1);
}
