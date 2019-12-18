/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreijola <sreijola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:28:44 by sreijola          #+#    #+#             */
/*   Updated: 2019/10/31 10:50:41 by sreijola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	fr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!fr)
		return (0);
	while (s1[i] != '\0')
	{
		fr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		fr[i] = s2[j];
		i++;
		j++;
	}
	fr[i] = '\0';
	return (fr);
}
