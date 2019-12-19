/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarkaus <mkarkaus@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:15:34 by mkarkaus          #+#    #+#             */
/*   Updated: 2019/12/19 13:15:46 by mkarkaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_pc(char *s)
{
	int	i;
	int	h;

	i = 0;
	h = 0;
	while (s[i] != '#')
		i++;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (i != 0 && s[i - 1] == '#')
				h++;
			if (i < 18 && s[i + 1] == '#')
				h++;
			if (i > 4 && s[i - 5] == '#')
				h++;
			if (i < 15 && s[i + 5] == '#')
				h++;
		}
		i++;
	}
	if (h != 6 && h != 8)
		return (-1);
	return (0);
}

int		ft_check_grid(char *s)
{
	int i;
	int	h;
	int	d;

	i = 0;
	h = 0;
	d = 0;
	while (s[i] != '\0' && (s[i] == '.' || s[i] == '#' || s[i] == '\n'))
	{
		if (s[i] == '.')
			d++;
		if (s[i] == '#')
			h++;
		i++;
	}
	if (h != 4 || d != 12 || s[4] != '\n' || s[9] != '\n' || s[14] != '\n' \
	|| s[19] != '\n' || (s[20] != '\n' && s[20] != '\0'))
		return (-1);
	if (ft_check_pc(s) == -1)
		return (-1);
	return (0);
}

char	**ft_read_pc(int fd)
{
	char			**b;
	struct s_piece	p;
	ssize_t			ret;
	int				pc;
	char			buff[BUFF_SIZE + 1];

	ret = 0;
	pc = 0;
	p.i = 0;
	if (!(p.pcs = (char ***)malloc(27 * sizeof(char **))))
		return (NULL);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (ft_check_grid(buff) == -1)
			return (NULL);
		if (++pc > 26)
			return (NULL);
		ft_trim_pc(buff, p, pc);
	}
	if (buff[20] == '\n' || buff[0] == '\0' || (b = ft_size_board(pc)) == NULL)
		return (NULL);
	ft_solver(&b, p, pc);
	return (b);
}
