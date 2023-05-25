/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 08:00:36 by joaoribe          #+#    #+#             */
/*   Updated: 2023/05/24 08:06:33 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	bf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*ln;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			ft_bzero(bf[fd], BUFFER_SIZE + 1);
		return (0);
	}
	ln = 0;
	while (*(bf[fd]) || read(fd, bf[fd], BUFFER_SIZE) > 0)
	{
		ln = ft_strjoin(ln, bf[fd]);
		if (nl(bf[fd]) == 1)
			break ;
	}
	return (ln);
}
