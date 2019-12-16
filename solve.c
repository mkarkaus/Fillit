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
	// printf("%s ", p.pcs[p.i][0]);
	if (!(p.pcs[p.i]))
		return (0);
	// if ()
	else if ((**board)[row] != NULL && ft_fitpc(board, p.pcs[p.i], row, col))
	{
		ft_putpc(&board, p.pcs[p.i], row, col);
		printf("%d %d pala\n", row, col);
		row = 0;
		while ((**board)[row] != NULL)
		{
			printf("%s\n", (**board)[row]);
			row++;
		}
		p.i++;
		if (ft_solveboard(board, p, 0, 0))
			return (1);
	}
	else if ((**board)[row] != NULL && (**board)[row][col + 1] != '\0')
	{
		printf("%d %d merkki etiappai\n", row, col);
		if (ft_solveboard(board, p, row, col + 1))
			return (1);
	}
	else if ((**board)[row] != NULL && (**board)[row][col + 1] == '\0')
	{
		printf("%d %d rivi etiappai\n", row, col);
		if (ft_solveboard(board, p, row + 1, 0))
			return (1);
	}
	else if ((**board)[row] == NULL && p.pcs[p.i][0] != NULL)
	{
		if (((**board) = ft_resizeboard(&board)) != NULL)
		{
			p.i = 0;
			if (ft_solveboard(board, p, 0, 0))// here pcs should go to 0
			{
				printf("%d %d %s isompi lauta\n", row, col, (**board)[0]);
				return (1);
			}
		}
		return (0);
	}
	printf("%d %d %s janna\n", row, col, (**board)[row]);
	return (0);// isompi lauta
}

void	ft_solver(char ***board, struct piece p)
{
	int		row;
	int		col;
	int		i;

	row = 0;
	col = 0;
	i = 0;
	ft_solveboard(&board, p, row, col);
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

// miikan kakkakoodi
//        |
//        V
// 
// void	ft_wipeboard(char ****board, int *row, int *col, int pc)
// {
// 	int		row2;
// 	int		col2;

// 	row2 = 0;
// 	col2 = 0;
// 	while ((**board)[row2])
// 	{
// 		while ((**board)[row2][col2] != '\0')
// 		{
// 			if ((**board)[row2][col2] == 'A' + pc)
// 				(**board)[row2][col2] = '.';
// 			col2++;
// 		}
// 		col2 = 0;
// 		row2++;
// 	}
// }

// // void	ft_fitpiece(char ****board, char ***pcs, int pc)
// // {

// // }
// void	ft_solver(char ***board, char ***pcs)
// {
// 	int		i;
// 	int		k;
// 	int		row;
// 	int		col;
// 	int		pc;

// 	i = 0;
// 	k = 0;
// 	pc = 0;
// 	row = 0;
// 	col = 0;
// 	while (pcs[pc] != NULL) //menee niin kauan kun paloja on
// 	{
// 		while (pcs[pc][k]) // menee niin kauan kun palassa on riveja
// 		{
// 			while (pcs[pc][k][i] != '\0' && (*board)[row]) // menee niin kauan kun rivissa on merkkeja ja laudassa on riveja
// 			{
// 				if ((*board)[row + k][col + i] == '.')
// 					(*board)[row + k][col + i] = pcs[pc][k][i];
// 				else if ((*board)[row + k][col + i] != '.') //&& (*board)[row + k][col + i] != '\0') //&& pcs[pc][k][i] != '.') // (same as only "else")
// 				{
// 					while ((*board)[row][col] != '.')
// 					{	
// 						if ((*board)[row][col + 1] != '\0')
// 							col++;
// 						else if ((*board)[row][col + 1] == '\0' && (*board)[row + 1] != NULL)
// 						{
// 							row++;
// 							col = 0;
// 						}
// 						k = 0;
// 						i = -1;
// 					}
// 				 	ft_wipeboard(&board, &row, &col, pc);					
// 				}
// 				i++;
// 			}
// 			i = 0;
// 			k++;
// 		}
// 		k = 0;
// 		if ((*board)[row][col + 1] != '\0')
// 			col++;
// 		else
// 		{
// 			row++;
// 			col = 0;
// 		}
// 		pc++;
// 	}
// }