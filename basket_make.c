/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basket_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:50:20 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 14:52:23 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	num[3] = {copy_i, copy_j, flag}
**			  0,	      1,    2
*/

void	isfirst(int *num, int i, int j)
{
	if (num[2] == 0)
	{
		num[0] = i;
		num[1] = j;
		num[2] = 1;
	}
}

void	one_figure(t_bask *basket, char **ret)
{
	int i;
	int j;
	int k;
	int num[3];
	int p;

	p = -1;
	while (++p < 3)
		num[p] = 0;
	k = 0;
	i = -1;
	while (ret[++i])
	{
		j = -1;
		while (ret[i][++j])
		{
			if (ret[i][j] == '#')
			{
				isfirst(num, i, j);
				basket->cord[k][0] = i - num[0];
				basket->cord[k][1] = j - num[1];
				k++;
			}
		}
	}
}

t_bask	**make_basket(char ***ret, int num)
{
	t_bask	**basket;
	int		i;
	char	c;

	c = 'A';
	i = 0;
	if (!(basket = (t_bask **)malloc(sizeof(t_bask**) * (num + 1))))
		return (NULL);
	while (*ret)
	{
		basket[i] = (t_bask *)malloc(sizeof(t_bask));
		one_figure(basket[i], *ret);
		basket[i]->print = c++;
		i++;
		ret++;
	}
	basket[i] = NULL;
	return (basket);
}
