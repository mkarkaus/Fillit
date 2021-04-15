/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:16:35 by mkarkaus          #+#    #+#             */
/*   Updated: 2021/04/15 15:21:25 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			k;
	char		**sboard;

	k = 0;
	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	sboard = ft_read_pc(fd);
	if (sboard == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
		while (sboard[k])
		{
			ft_putendl(sboard[k]);
			k++;
		}
	return (0);
}
