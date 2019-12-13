
#include "fillit.h"

int		ft_checkpc(char *s)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (s[i] != '#')
		i++;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (i != 0 && s[i - 1] == '#')
				h++;
			if (i < 18 && s[i + 1] == '#')
				h++;
			if (i > 4 && s[i - 5] == '#')
				h++;
			if (i < 15 && s[i + 5] == '#')
				h++;
		}
		i++;
	}
	if (h != 6 && h != 8)
		return (-1);
	return (0);
}

int		ft_checkgrid(char *s)
{
	int i;
	int	h;
	int	d;

	i = 0;
	h = 0;
	d = 0;
	while (s[i] != '\0' && (s[i] == '.' || s[i] == '#' || s[i] == '\n'))	//check that all chars are allowed
	{
		if (s[i] == '.')
			d++;
		if (s[i] == '#')
			h++;
		i++;
	}
	if (h != 4 || d != 12 || s[4] != '\n' || s[9] != '\n' || s[14] != '\n' || 
			s[19] != '\n' || (s[20] != '\n' && s[20] != '\0'))
		return (-1);
	if (ft_checkpc(s) == -1)
		return (-1);
	return (0);
}

char	**ft_readpc(int fd)
{
	char			**board;
	static char		***pcs;
	ssize_t 		ret;
	int				pc;
	char 			buff[BUFF_SIZE + 1];
	int				i;
	int				k;

	i = 0;
	k = 0;
	ret = 0;
	pc = 0;
	board = NULL;
	if (!(pcs = (char ***)malloc(27 * sizeof(char **))))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ft_checkgrid(buff) == -1)
			return (NULL);
		if (++pc > 26)
			return (NULL);
		ft_trimpc(buff, pcs, pc);
	}
	if ((board = ft_sizeboard(board, pc)) == NULL)
		return (NULL);
	ft_solver(board, pcs);
	// while (pcs[k] != NULL)
	// {
	// 	while (pcs[k][i] != NULL)
	// 	{
	// 		printf("%s", pcs[k][i]);
	// 		printf("\n");
	// 		i++;
	// 	}
	// 	i = 0;
	// 	printf("\n");
	// 	if (pcs[k + 1] != NULL)
	// 		k++;
	// 	else
	// 		break;
	// }
	return (board);
}

int		main(int ac, char **av)
{
	int			fd;
	int			k;
	char		**sboard;

	k = 0;
	if (ac != 2)
	{
		write (1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	sboard = ft_readpc(fd);
	if (sboard == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	while (sboard[k])
	{
		printf("%s", sboard[k]);
		printf("%c", '\n');
		k++;
	}
//	 while (1);
	// write(1, "valid\n", 6);
//	while (1); TESTAA VUODOT TAI VAIHTOEHTOISESTI KAYTA system(leaks fillit);
	return (0);
}

// system function in stdlib system(leaks fillit);
// every Tetrimino must exactly fit in a
// 4 by 4 chars square and all Tetrimino are separated by an newline each.
// If the number of parameters sent to your executable is not 1, your program must display
// its usage and exit properly (give info on what is missing)

// the smallest is the one at tmost top left corner of the multiple solutions
// trim 12 empties when assembling board
// assign capital letters to # on each piece

// If the file contains at least one error, your program must display error on the standard output followed by a newline and have to exit properly.


// All your sources and headers must be in the same folder. You can have
// two different folders, one for the libft and one for fillit.

// - pitääkö aluksi tehdä neliölauta jolle mahtuu kaikki palat trimmaamatta?
// - IF \n followed by \n, palikka vaihtuu, jos myös ret == 0 ni tiedoston loppu

