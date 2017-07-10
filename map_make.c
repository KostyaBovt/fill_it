/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:20:59 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 16:21:04 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		numfigures(char ***ret)
{
	int i;

	i = 0;
	while (ret[i])
		i++;
	return (i);
}

char	**make_map(int num)
{
	char	**map;
	int		value;
	int		i;
	int		j;

	value = 2;
	i = -1;
	while ((value * value) < (num * 4))
		value++;
	if (!(map = (char**)malloc(sizeof(char**) * (value + 1))))
		return (NULL);
	while (++i < value)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (value + 1))))
			return (NULL);
		j = -1;
		while (++j < value)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

void	print_map(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			ft_putchar(map[i][j]);
		ft_putchar('\n');
	}
}
