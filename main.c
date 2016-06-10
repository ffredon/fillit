/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:51:13 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:32:29 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*tab;
	int		i;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if ((i = ft_read_size(argv)) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	tab = (char*)malloc(sizeof(*tab) * i + 1);
	if (tab == NULL)
		return (0);
	tab = ft_read_tab(argv, tab);
	if (ft_test2(tab) == 0 || ft_fillit(tab) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	free(tab);
	return (0);
}
