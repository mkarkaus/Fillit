#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

static struct piece
{
	char	***pcs;
	int			i;
} 				p;

void			ft_removepc(char *****board, char **pc, int row, int col);
int				ft_solveboard(char ****board, struct piece p, int row, int col);
void			ft_solver(char ***board, struct piece p);
void			ft_trimpc(char *s, struct piece p, int pc);
int				ft_checkgrid(char *s);
int				ft_checkpc(char *s);
char			**ft_readpc(int fd);
char			**ft_resizeboard(char ****board);
char			**ft_sizeboard(int pc);
void			ft_fill_board(char ***board, int w_and_h);

#endif