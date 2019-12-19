#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

static struct	s_piece
{
	char	***pcs;
	int		i;
}				p;

void			ft_trim_sides(char ***arr);
void			ft_trim_top_bot(char ***arr);
void			ft_put_pc(char *****brd, char **pc, int row, int col);
int				ft_fit_pc(char ****brd, char **pcs, int row, int col);
void			ft_remove_pc(char *****brd, char **pc, int row, int col);
int				ft_solve_brd(char ****brd, struct s_piece p, int y, int x);
void			ft_solver(char ***brd, struct s_piece p, int pc);
void			ft_trim_pc(char *s, struct s_piece p, int pc);
int				ft_check_grid(char *s);
int				ft_check_pc(char *s);
char			**ft_read_pc(int fd);
char			**ft_resize_board(char ****board);
char			**ft_size_board(int pc);
void			ft_fill_board(char ***board, int w_and_h);

#endif
