#include "fillit.h"

int		ft_fitpc(char ****board, char **pcs, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pcs[k] && (**board)[row + k])
	{
		
		while (pcs[k][i] != '\0')
		{
			if (pcs[k][i] != '.' && (**board)[row + k][col + i] != '.')
				return (0);
			i++;
		}
		i = 0;
		if (pcs[k + 1] != NULL && (**board)[row + k] != NULL)
			k++;
		else
			break;
	}
	if (pcs[k] && (**board)[row + k] == NULL)
		return (0);
	return (1);
}

void	ft_removepc(char *****board, char **pc, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pc[k])
	{
		while (pc[k][i] != '\0')
		{
			if (pc[k][i] == (***board)[row + k][col + i])
				(***board)[row + k][col + i] = '.';
			i++;
		}
		i = 0;
		k++;
	}
}

void	ft_putpc(char *****board, char **pc, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pc[k])
	{
		while (pc[k][i] != '\0')
		{
			if (pc[k][i] != '.' && (***board)[row + k][col + i] == '.')
				(***board)[row + k][col + i] = pc[k][i];
			i++;
		}
		i = 0;
		k++;
	}
}


int		ft_solveboard(char ****board, struct piece p, int row, int col)
{
	if (!(p.pcs[p.i]))
		return (1);
	else if ((**board)[row] != NULL)
	{
		if ((ft_fitpc(board, p.pcs[p.i], row, col)))
		{
			ft_putpc(&board, p.pcs[p.i], row, col);
			p.i++;
			if (ft_solveboard(board, p, 0, 0))
				return (1);
			else
			{
				p.i--;
				ft_removepc(&board, p.pcs[p.i], row, col);
					if (ft_solveboard(board, p, row, col + 1))
					return (1);
			}
		}
		else if ((**board)[row][col + 1] != '\0')
		{
			if (ft_solveboard(board, p, row, col + 1))
				return (1);
		}
		else if ((**board)[row][col + 1] == '\0')
			if (ft_solveboard(board, p, row + 1, 0))
				return (1);
	}
	return (0);
}

void	ft_solver(char ***board, struct piece p)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	while(!(ft_solveboard(&board, p, row, col)))
		(*board) = ft_resizeboard(&board);
}
