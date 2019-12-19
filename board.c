#include "fillit.h"

char	**ft_resize_board(char ****board)
{
	char	**newboard;
	int		w_and_h;
	int		i;

	i = ft_strlen((**board)[0]);
	w_and_h = ft_strlen((**board)[0]) + 1;
	while (i >= 0)
	{
		free((**board)[i]);
		i--;
	}
	i = 0;
	free((**board));
	if (!(newboard = (char **)malloc((w_and_h + 1) * sizeof(char *))))
		return (NULL);
	while (i < w_and_h)
	{
		if (!(newboard[i] = (char *)malloc((w_and_h + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	ft_fill_board((&newboard), w_and_h);
	return (newboard);
}

void	ft_fill_board(char ***board, int w_and_h)
{
	int		i;
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

char	**ft_size_board(int pc)
{
	char	**board;
	int		w_and_h;
	int		numblock;
	int		i;

	board = NULL;
	i = 0;
	w_and_h = 2;
	numblock = pc * 4;
	while (w_and_h * w_and_h < numblock)
		w_and_h++;
	if (!(board = (char **)malloc((w_and_h + 1) * sizeof(char *))))
		return (NULL);
	while (i < w_and_h)
	{
		if (!(board[i] = (char *)malloc((w_and_h + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	ft_fill_board(&board, w_and_h);
	return (board);
}
