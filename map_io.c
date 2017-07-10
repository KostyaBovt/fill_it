/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:19:28 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 16:19:32 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_fig(char **map, t_bask *figure, int pos, int len)
{
	int	i;
	int	j;
	int n;

	i = pos / len;
	j = pos % len;
	n = -1;
	while (++n < 4)
		map[i + figure->cord[n][0]][j + figure->cord[n][1]] = figure->print;
}

void	del_fig(char **map, t_bask *figure, int pos, int len)
{
	int	i;
	int	j;
	int n;

	i = pos / len;
	j = pos % len;
	n = -1;
	while (++n < 4)
		map[i + figure->cord[n][0]][j + figure->cord[n][1]] = '.';
}

int		can_put(char **map, t_bask *figure, int pos, int len)
{
	int n;
	int i;
	int j;

	i = pos / len;
	j = pos % len;
	n = -1;
	if (map[figure->cord[0][0] + i][figure->cord[0][1] + j] != '.')
		return (0);
	while (++n < 4)
		if (figure->cord[n][0] + i < 0 || figure->cord[n][0] + i >= len || \
			figure->cord[n][1] + j < 0 || figure->cord[n][1] + j >= len)
			return (0);
	n = -1;
	while (++n < 4)
		if (map[figure->cord[n][0] + i][figure->cord[n][1] + j] != '.')
			return (0);
	return (1);
}
