/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 11:03:46 by fredon            #+#    #+#             */
/*   Updated: 2015/12/12 16:38:12 by vronveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct		s_list
{
	int				check;
	char			value;
	char			**tab;
	struct s_list	*next;
	struct s_list	*begin;
}					t_list;

char				*ft_str(char **tab, char *str, int x, int y);
int					ft_test3(char *tab, int i);
int					ft_test1(char *tab, int i, int n);
int					ft_check3(char *tab, int i, int n);
int					ft_checkl(int n);
int					ft_checkfinal(char *tab, int i, int n);
int					ft_print2(char **tab);
int					ft_piece(char **tab, int x, int y);
int					ft_test2(char *tab);
int					ft_checknorm(char c);
int					ft_checkn(char c);
int					ft_checkend(char *tab, int i, int n);
int					ft_fillit(char *tab);
char				*ft_read_tab(char **argv, char *tab);
int					ft_read_size(char **argv);
int					ft_getnb(char *tab);
int					ft_tabid(int nb);
char				**ft_newtab(int i, char **table);
int					ft_loop(int i, char *tab);
int					ft_backtrack(char **table, char *tab);
char				**ft_maketab(char *tab);
char				**ft_tab1(char *tab, char **table);
char				**ft_tab2(char **tab);
int					ft_srch(char **tab, int x, int y);
int					ft_comp(char **table, t_list *lst, int x, int y);
t_list				*ft_gtvalues(t_list *lst, char value, char *tab, t_list *b);
t_list				*ft_assign(char *tab);
void				ft_print(char **table);
int					ft_srch2(char **tab, int x, int y);
int					ft_checklst(t_list *lst);
int					ft_do(char **table, t_list *lst, int x, int y);
int					ft_replace(char **table, t_list *lst, int x, int y);
int					ft_delete(char **table, t_list *lst, int x, int y);
#endif
