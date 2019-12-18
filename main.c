#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			k;
	char		**sboard;

	k = 0;
	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 26);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	sboard = ft_readpc(fd);
	if (sboard == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
		while (sboard[k])
		{
			ft_putendl(sboard[k]);
			k++;
		}
	return (0);
}
