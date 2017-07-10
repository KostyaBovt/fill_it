/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:00:40 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 15:07:50 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_bask
{
	char	print;
	int		cord[4][2];
}				t_bask;

void			ft_putchar(char c);
void			ft_putstr(char const *s);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			error(int n);
char			*get_inpt(char *file_name);
int				check_inpt(char *inpt);
char			***trans_inpt(char *inpt);
int				check_figure(char ***ret);
int				check_nums(char **ret);
int				check_lnks(char **ret);
int				lnks_for_one(char **ret, int i, int j);
void			isfirst(int *num, int i, int j);
void			one_figure(t_bask *basket, char **ret);
t_bask			**make_basket(char ***ret, int num);
void			put_fig(char **map, t_bask *figure, int pos, int len);
void			del_fig(char **map, t_bask *figure, int pos, int len);
int				can_put(char **map, t_bask *figure, int pos, int len);
int				numfigures(char ***ret);
char			**make_map(int num);
void			print_map(char **map);
int				map_len(char **map);
int				solve_tetris(char **map, t_bask	**basket, int pos, int len);
void			tetris(t_bask **basket, int n);
int				return_pos(char **map, t_bask **basket, int pos, int len);

#endif
