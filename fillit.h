#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21 // so it will read one piece at a time
# include "miikan_sooloilut/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

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

//TO REMOVE
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG     "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
//TO REMOVE

#endif