#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21 // so it will read one piece at a time
#include "includes/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		*make_block(char *file);

#endif