#include "fillit.h"

void	ft_fill_board(char ***board, int w_and_h)
{
	int		i; //miksi nama on erivarisia kuin muut parametrit
	int		row;

	i = 0;
	row = 0;
	while (row < w_and_h)
	{
		while (i < w_and_h)
		{
			(*board)[row][i] = '.';
			i++;
		}
		(*board)[row][i] = '\0';
		i = 0;
		row++;
	}
	(*board)[row] = NULL;
}

char	**ft_sizeboard(char **board, int pc)
{
	int		w_and_h;
	int		numblock;
	int		i;

	i = 0;
	if (board)
		w_and_h = (ft_strlen(board[0]) + 1);
	else
	{
		w_and_h = 2;
		numblock = pc * 4;
		while (w_and_h * w_and_h < numblock)
			w_and_h++;
	}
	if (!(board = (char **)malloc((w_and_h + 1) * sizeof(char *))))
		return (NULL);
	while (i < w_and_h) // vai pitaako laittaa myos nullille
	{
		if (!(board[i] = (char *)malloc((w_and_h + 1) * sizeof(char))))	
			return (NULL);
		i++;
	}
	ft_fill_board(&board, w_and_h);
	return (board);
}