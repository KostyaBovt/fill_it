/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:53:05 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 14:59:05 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lnks_for_one(char **ret, int i, int j)
{
	int count;

	count = 0;
	if (i != 0)
		if (ret[i - 1][j] == '#')
			count++;
	if (i != 3)
		if (ret[i + 1][j] == '#')
			count++;
	if (j != 0)
		if (ret[i][j - 1] == '#')
			count++;
	if (j != 3)
		if (ret[i][j + 1] == '#')
			count++;
	return (count);
}

int		check_lnks(char **ret)
{
	int i;
	int j;
	int lnks;

	i = 0;
	lnks = 0;
	while (ret[i])
	{
		j = 0;
		while (ret[i][j])
		{
			if (ret[i][j] == '#')
				lnks += lnks_for_one(ret, i, j);
			j++;
		}
		i++;
	}
	return ((lnks > 5) ? 1 : 0);
}

int		check_nums(char **ret)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (ret[i])
	{
		j = 0;
		while (ret[i][j])
		{
			if (ret[i][j] == '#')
				count++;
			j++;
		}
		i++;
	}
	return ((count == 4) ? 1 : 0);
}

int		check_figure(char ***ret)
{
	while (*ret)
	{
		if (!check_lnks(*ret) || !check_nums(*ret))
			return (0);
		ret++;
	}
	return (1);
}
