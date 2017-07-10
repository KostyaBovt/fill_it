/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:23:28 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 16:23:32 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_len(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		return_pos(char **map, t_bask **basket, int pos, int len)
{
	int count;

	count = -1;
	pos = (pos == len * len) ? 0 : pos;
	while (!can_put(map, *basket, pos, len) && ++count < len * len)
	{
		pos++;
		pos = (pos == len * len) ? 0 : pos;
	}
	if (count + 1 >= len * len)
		return (-1);
	return (pos);
}

int		solve_tetris(char **map, t_bask **basket, int pos, int len)
{
	int		f;
	int		f_pos;

	if (*basket == NULL)
		return (1);
	if ((pos = return_pos(map, basket, pos, len)) == -1)
		return (0);
	f_pos = pos;
	f = 1;
	while (f)
	{
		if (can_put(map, *basket, pos, len))
		{
			put_fig(map, *basket, pos, len);
			if (solve_tetris(map, basket + 1, 0, len))
				return (1);
			del_fig(map, *basket, pos, len);
		}
		pos++;
		pos = (pos == len * len) ? 0 : pos;
		f = (f_pos == pos) ? 0 : f;
	}
	return (0);
}

void	tetris(t_bask **basket, int n)
{
	char **map;

	while (1)
	{
		map = make_map(n);
		if (solve_tetris(map, basket, 0, map_len(map)))
		{
			print_map(map);
			return ;
		}
		else
			n++;
	}
}
