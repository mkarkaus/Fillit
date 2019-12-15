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
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	static char	*pieces[4];
	ssize_t ret;
	char *temp;
	char buff[BUFF_SIZE + 1];

	ret = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (pieces[fd] == NULL)
			pieces[fd] = ft_strnew(0);
		while ((ret = read(fd, buff, BUFF_SIZE)))
		{
			buff[ret] = '\0';
			temp = ft_strjoin(pieces[fd], buff);
			free(pieces[fd]);
			pieces[fd] = temp;
		}
		printf(pieces[fd]);
	}
	return (0);
}
