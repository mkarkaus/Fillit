#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21 // so it will read one piece at a time
# include "miikan_sooloilut/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

int				ft_solveboard(char ****board, char ***pcs, int row, int col);
void			ft_solver(char ***board, char ***pcs);
void			ft_trimpc(char *s, char ****pcs, int pc);
int				ft_checkgrid(char *s);
int				ft_checkpc(char *s);
char			**ft_readpc(int fd);
int				ft_resizeboard(char *****board);
char			**ft_sizeboard(int pc);
void			ft_fill_board(char ***board, int w_and_h);

#endif