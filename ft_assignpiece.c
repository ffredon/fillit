/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:16:43 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:29:01 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_maketab(char *tab)
{
	char	**table;

	if ((table = (char**)malloc(sizeof(*table) * 5)) == 0)
		return (NULL);
	table = ft_tab1(tab, table);
	table = ft_tab2(table);
	return (table);
}

char	**ft_tab1(char *tab, char **table)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (tab[i] && (!(tab[i] == '\n' && tab[i - 1] == '\n')))
	{
		if ((table[y] = (char *)malloc(sizeof(char *) * 5)) == 0)
			return (NULL);
		while (tab[i] && tab[i] != '\n')
		{
			table[y][x] = tab[i];
			x++;
			i++;
		}
		table[y][x] = '\0';
		x = 0;
		y++;
		i++;
	}
	table[y] = NULL;
	return (table);
}

char	**ft_tab2(char **tab)
{
	char	**tab2;
	int		x;
	int		y;
	int		j;

	j = 0;
	x = 0;
	y = 0;
	x = ft_srch(tab, x, y);
	y = ft_srch2(tab, x, y);
	if ((tab2 = (char**)malloc(sizeof(*tab2) * (5 - y))) == 0)
		return (NULL);
	while (tab[y])
	{
		if ((tab2[j] = (char *)malloc(sizeof(char *) * (5 - x))) == 0)
			return (NULL);
		tab2[j] = ft_str(tab, tab2[j], x, y);
		j++;
		y++;
	}
	tab2[j] = NULL;
	free(tab);
	return (tab2);
}
