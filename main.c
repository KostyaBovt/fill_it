/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:31:03 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 18:55:34 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*inpt;
	char	***tab;
	t_bask	**basket;
	int		f;

	f = 0;
	if (argc != 2)
	{
		error(1);
		return (0);
	}
	if ((inpt = get_inpt(argv[1])) != NULL)
		if (check_inpt(inpt))
		{
			tab = trans_inpt(inpt);
			if (check_figure(tab))
			{
				basket = make_basket(tab, numfigures(tab));
				tetris(basket, numfigures(tab));
				f = 1;
			}
		}
	if (!f)
		error(2);
	return (0);
}
