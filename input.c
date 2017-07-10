/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:13:46 by kbovt             #+#    #+#             */
/*   Updated: 2016/12/12 15:26:55 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_inpt(char *file_name)
{
	int		fd;
	char	*buff;
	char	*ret;
	int		len;
	char	*one;

	if (!(buff = (char*)malloc(sizeof(char) * 546)))
		return (NULL);
	if (!(one = (char*)malloc(sizeof(char) * 1)))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if ((len = read(fd, buff, 545)) == 0)
		return (NULL);
	buff[len] = '\0';
	if (read(fd, one, 1) != 0)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (len + 1));
	ret = ft_strcpy(ret, buff);
	free(buff);
	free(one);
	return (ret);
}

int		check_inpt(char *inpt)
{
	int	i;

	if ((ft_strlen(inpt) + 1) % 21 != 0)
		return (0);
	i = 0;
	while (inpt[i])
	{
		if ((i + 1) % 21 == 0 || (i + 1) % 21 % 5 == 0)
		{
			if (inpt[i] != '\n')
				return (0);
		}
		else if (inpt[i] != '.' && inpt[i] != '#')
			return (0);
		i++;
	}
	return (1);
}

char	***trans_inpt(char *inpt)
{
	char	***ret;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = (ft_strlen(inpt) + 1) / 21;
	ret = (char***)malloc(sizeof(char***) * (len + 1));
	ret[len] = NULL;
	while (len)
	{
		ret[i] = (char**)malloc(sizeof(char**) * 5);
		ret[i][4] = NULL;
		j = -1;
		while (++j < 4)
		{
			ret[i][j] = (char*)malloc(sizeof(char) * 5);
			ft_strncpy(ret[i][j], inpt, 4);
			inpt = inpt + ((inpt[5]) ? 5 : 0);
		}
		inpt++;
		i++;
		len--;
	}
	return (ret);
}
