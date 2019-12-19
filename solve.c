/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:16:04 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/12/19 13:16:17 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fit_pc(char ****brd, char **pcs, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pcs[k] && (**brd)[row + k])
	{
		while (pcs[k][i] != '\0')
		{
			if (pcs[k][i] != '.' && (**brd)[row + k][col + i] != '.')
				return (0);
			i++;
		}
		i = 0;
		if (pcs[k + 1] != NULL && (**brd)[row + k] != NULL)
			k++;
		else
			break ;
	}
	if (pcs[k] && (**brd)[row + k] == NULL)
		return (0);
	return (1);
}

void	ft_remove_pc(char *****brd, char **pc, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pc[k])
	{
		while (pc[k][i] != '\0')
		{
			if (pc[k][i] == (***brd)[row + k][col + i])
				(***brd)[row + k][col + i] = '.';
			i++;
		}
		i = 0;
		k++;
	}
}

void	ft_put_pc(char *****brd, char **pc, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pc[k])
	{
		while (pc[k][i] != '\0')
		{
			if (pc[k][i] != '.' && (***brd)[row + k][col + i] == '.')
				(***brd)[row + k][col + i] = pc[k][i];
			i++;
		}
		i = 0;
		k++;
	}
}

int		ft_solve_brd(char ****brd, struct s_piece p, int y, int x)
{
	if (!(p.pcs[p.i]))
		return (1);
	else if ((**brd)[y] != NULL)
	{
		if ((ft_fit_pc(brd, p.pcs[p.i], y, x)))
		{
			ft_put_pc(&brd, p.pcs[p.i], y, x);
			p.i++;
			if (ft_solve_brd(brd, p, 0, 0))
				return (1);
			else
			{
				p.i--;
				ft_remove_pc(&brd, p.pcs[p.i], y, x);
				if (ft_solve_brd(brd, p, y, x + 1))
					return (1);
			}
		}
		else if ((**brd)[y][x + 1] != '\0' && ft_solve_brd(brd, p, y, x + 1))
			return (1);
		else if ((**brd)[y][x + 1] == '\0' && ft_solve_brd(brd, p, y + 1, 0))
			return (1);
	}
	return (0);
}

void	ft_solver(char ***brd, struct s_piece p, int pc)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (!(ft_solve_brd(&brd, p, row, col)))
		(*brd) = ft_resize_board(&brd);
	while (pc - 1 >= 0)
	{
		p.i = 0;
		while (p.pcs[pc - 1][p.i] != NULL)
			p.i++;
		while (p.i > 0)
		{
			free(p.pcs[pc - 1][p.i - 1]);
			p.i--;
		}
		free(p.pcs[pc]);
		pc--;
	}
	free(p.pcs[pc]);
	free(p.pcs);
}
