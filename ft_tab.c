/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:30:13 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:30:22 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read_size(char **argv)
{
	int		i;
	char	c;
	int		fd;

	i = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while (read(fd, &c, 1))
		i++;
	if (close(fd) == -1)
		return (0);
	return (i);
}

char	*ft_read_tab(char **argv, char *tab)
{
	int		i;
	char	c;
	int		fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (read(fd, &c, 1))
	{
		tab[i] = c;
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	tab[i] = '\0';
	return (tab);
}
