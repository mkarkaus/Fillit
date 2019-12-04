#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21 // so it will read one piece at a time
# include "miikan_sooloilut/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int		ft_checkgrid(char *s);
int		ft_checkpc(char *s);

#endif