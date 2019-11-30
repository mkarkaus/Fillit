/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:15:50 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/11/29 15:31:25 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* might have to save blocks with linked lists */
/* or with array of array of ints if that exists */

#include "includes/fillit.h"

int		*make_block(char *file)
{
	char		*temp;
	size_t		num;
	size_t		i;
	int			arr[4];

	num = 0;
	i = 0;

	while (file[i])
	{
		file = ft_strchr(file, '#');
		i = 0;
		while (file[i] != '\n' && file[i + 1] != '\n')
		{
			if (file[i] == '#')
			{
				arr[num] = i;
				num++;
			}
			i++;
		}
		*file = *file + i + 2;
	}
	return (arr);
}
