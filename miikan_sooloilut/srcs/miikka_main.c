
#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*file;
	char	*line;

	if (argc > 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		file = ft_strjoin(file, line);
		free(line);
	}
	close(fd);
}
