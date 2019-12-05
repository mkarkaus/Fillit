#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21 // so it will read one piece at a time
# include "miikan_sooloilut/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

// typedef struct	s_list
// {
// 	char 			**leanpc;
// 	int				leveys;
// 	int 			korkeus;
// 	struct s_list	*next;
// };				t_tetrpc;

//t_tetrpc			ft_trim_pc(char *s);
int				ft_checkgrid(char *s);
int				ft_checkpc(char *s);
char			*ft_readpc(int fd, char **map);
char			**ft_sizeboard(int pc);
void			ft_fill_board(char ***board, int w_and_h);

#endif