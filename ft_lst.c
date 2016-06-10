/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 14:33:45 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:30:49 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_gtvalues(t_list *lst, char value, char *tab, t_list *b)
{
	lst->value = value;
	lst->check = 0;
	lst->tab = ft_maketab(tab);
	lst->begin = b;
	return (lst);
}

t_list	*ft_assign(char *tab)
{
	t_list	*lst;
	t_list	*begin_list;
	t_list	*next;
	char	value;

	next = NULL;
	lst = (t_list*)malloc(sizeof(t_list) * 28);
	value = 'A';
	lst = ft_gtvalues(lst, value, tab, lst);
	lst->next = next;
	begin_list = lst;
	value++;
	tab = tab + 21;
	while (*(tab - 1))
	{
		next = (t_list*)malloc(sizeof(t_list));
		next = ft_gtvalues(next, value, tab, begin_list);
		next->next = NULL;
		lst->next = next;
		lst = next;
		value++;
		tab = tab + 21;
	}
	return (begin_list);
}
