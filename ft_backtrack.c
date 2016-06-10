/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 09:26:55 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:30:34 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_checklst(t_list *lst)
{
	t_list	*next;

	next = NULL;
	while (lst && lst->check == 1)
	{
		next = lst->next;
		lst = next;
	}
	if (!lst)
		return (1);
	return (0);
}

int		ft_do(char **table, t_list *lst, int x, int y)
{
	char	**tab;
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	j = 0;
	tab = lst->tab;
	while (tab[j] && table[y + j])
	{
		while (table[j + y][i + x])
		{
			if (tab[j][i] == '#' && table[y + j][x + i] == '.')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}

int		ft_replace(char **table, t_list *lst, int x, int y)
{
	int		j;
	int		i;
	char	**tab;

	i = 0;
	j = 0;
	tab = lst->tab;
	while (tab[j] && table[y + j])
	{
		while (tab[j][i] && table[y + j][i + x])
		{
			if (tab[j][i] == '#' && table[y + j][x + i] == '.')
				table[y + j][x + i] = lst->value;
			i++;
		}
		i = 0;
		j++;
	}
	lst->check = 1;
	if (ft_checklst(lst->begin) == 1)
		return (ft_print2(table));
	if (ft_comp(table, lst->next, 0, 0) == 1)
		return (1);
	return (ft_delete(table, lst, x, y));
}

int		ft_delete(char **table, t_list *lst, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (table[j])
	{
		while (table[j][i])
		{
			if (table[j][i] == lst->value)
				table[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	lst->check = 0;
	return (ft_comp(table, lst, x + 1, y));
}

int		ft_comp(char **table, t_list *lst, int x, int y)
{
	if (ft_checklst(lst->begin) == 1)
	{
		ft_print(table);
		return (1);
	}
	if ((table[y + 1]) && (!table[y][x]))
		return (ft_comp(table, lst, 0, y + 1));
	else if (!table[y + 1] && (!table[y][x]))
		return (0);
	if (lst->check == 1 && lst->next)
		return (ft_comp(table, lst->next, x, y));
	if (ft_do(table, lst, x, y) == 4)
		return (ft_replace(table, lst, x, y));
	else
		return (ft_comp(table, lst, x + 1, y));
}
