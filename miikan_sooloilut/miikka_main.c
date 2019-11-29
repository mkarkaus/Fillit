#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*file;
	char	**line;


	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		file = ft_strjoin(file, &line);
		free(line);
	}
	close(fd);
}