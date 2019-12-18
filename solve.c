// pitaa tsekata ettei mikaan palan osa ole toisen paalla
//pitaa palauttaa lauta, jos kaikki palat mahtuvat
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

void	ft_removepcs(char *****board, char **pc, int row, int col)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (pc[k])
	{
		//printf("[%d][%d]\n", k, i);
		while (pc[k][i] != '\0')
		{
			if (pc[k][i] == (***board)[row + k][col + i])
			{
				(***board)[row + k][col + i] = '.';
			}	
			i++;
		}
		i = 0;
		k++;
	}
	//printf("\n");
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

void ft_print(char ****board)
{
	int row;			
	row = 0;
	while ((**board)[row] != NULL)
	{
	printf(YEL"%s\n"RESET, (**board)[row]);
	row++;
	}
	printf("\n");
}

int		ft_solveboard(char ****board, struct piece p, int row, int col)
{
	if (!(p.pcs[p.i]))
		return (1);
	//while (p.pcs[p.i] && )
	else if ((**board)[row] != NULL)
	{
		if ((ft_fitpc(board, p.pcs[p.i], row, col)))
		{
			ft_print(board);
			//printf(BLU" before: PC*%d* [%d][%d] = %c\n " RESET, p.i, row, col, (**board)[row][col]);
			ft_putpc(&board, p.pcs[p.i], row, col);
			ft_print(board);
			//printf(GRN" after: PC*%d* [%d][%d] = %c\n " RESET, p.i, row, col, (**board)[row][col]);
			p.i++;
			if (ft_solveboard(board, p, 0, 0))
				return (1);
			else
		{
			p.i--;
		//printf(YEL" before: PC*%d* [%d][%d] = %c\n " RESET, p.i, row, col, (**board)[row][col]);
			ft_removepcs(&board, p.pcs[p.i], row, col);
			if (ft_solveboard(board, p, row, col + 1))
				return (1);
			// printf(MAG" before: PC*%d* [%d][%d] = %c\n " RESET, p.i, row, col, (**board)[row][col]);
			// printf("hello2\n");
		}
				
			//ft_putpc(&board, p.pcs[p.i], row, col);
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
	//else if ((**board)[row] == NULL && p.pcs[p.i][0] != NULL) //tahan backtrack
	// {
	// // 	col++;
	// //  	ft_solveboard(board, p, 0, col);
	// //  		return (1);
	// }
	return (0);// isompi lauta
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

// int		solveboard(int **board, int row, int col)
// {
// 	int number;
// ​
// 	if (row == 9)
// 		return (1);
// 	number = 1;
// 	while (number < 10)
// 	{
// 		if (validate(number, board, row, col))
// 		{
// 			board[row][col] = number;
// 			if (col == 8)
// 			{
// 				if (solveboard(board, row + 1, 0))
// 					return (1);
// 			}
// 			else
// 			{
// 				if (solveboard(board, row, col + 1))
// 					return (1);
// 			}
// 			board[row][col] = 0;
// 		}
// 		number++;
// 	}
// 	return (0);
// }