#include "fillit.h"

void	ft_trim_top_bot(char ***arr)
{
	int			row;
	int			col;
	int			k;

	k = 3;
	row = 0;
	col = 0;
	while ((*arr)[row])
	{
		while (!(ft_strchr((*arr)[row], '#')))
		{
			while ((*arr)[row + 1] != NULL)
			{
				(*arr)[row] = ft_strcpy((*arr)[row], (*arr)[row + 1]);
				row++;
			}
			free((*arr)[k]);
			(*arr)[k] = NULL;
			k--;
			row = 0;
		}
		row++;
	}
}

void	ft_trim_sides(char ***arr)
{
	int			row;
	int			col;
	int			temp;

	temp = 0;
	row = 0;
	col = 0;
	while ((*arr)[0][col] == '#' || (*arr)[1][col] == '#'\
		|| (*arr)[2][col] == '#' || (*arr)[3][col] == '#')
		col++;
	if ((*arr)[0][col] != '\0')
		while ((*arr)[row])
		{
			temp = col;
			while ((*arr)[row][col] != '\0')
			{
				(*arr)[row][col] = (*arr)[row][col + 1];
				col++;
			}
			col = temp;
			row++;
		}
}

void	ft_trim_pc(char *s, struct s_piece p, int pc)
{
	char		**arr;
	int			row;
	int			i;

	i = 0;
	row = 0;
	arr = ft_strsplit(s, '\n');
	while (row++ < 4)
		ft_trim_sides(&arr);
	ft_trim_top_bot(&arr);
	row = 0;
	while (arr[row])
	{
		while (arr[row][i] != '\0')
		{
			if (arr[row][i] == '#')
				arr[row][i] = (pc - 1 + 'A');
			i++;
		}
		i = 0;
		row++;
	}
	(p.pcs)[pc - 1] = arr;
	(p.pcs)[pc] = NULL;
}
