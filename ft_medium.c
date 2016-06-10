/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:05:58 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:31:01 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(char *tab)
{
	int		i;
	int		nb;

	nb = ft_getnb(tab);
	i = ft_tabid(nb);
	if (ft_loop(i, tab) == 0)
		return (0);
	return (1);
}

int		ft_loop(int i, char *tab)
{
	char **table;

	table = (char **)malloc(sizeof(*table) * (i + 1));
	if (table == NULL)
		return (0);
	table = ft_newtab(i, table);
	if (ft_backtrack(table, tab) == 0)
	{
		free(table);
		return (ft_loop(i + 1, tab));
	}
	return (1);
}

int		ft_backtrack(char **table, char *tab)
{
	t_list	*lst;
	int		x;
	int		y;

	lst = ft_assign(tab);
	x = 0;
	y = 0;
	if (ft_comp(table, lst, x, y) == 0)
		return (0);
	return (1);
}
