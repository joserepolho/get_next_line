/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 05:12:20 by joaoribe          #+#    #+#             */
/*   Updated: 2023/05/19 05:58:05 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	char		*ln;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_bzero(bf, BUFFER_SIZE + 1);
		return (0);
	}
	ln = 0;
	while (*bf || read(fd, bf, BUFFER_SIZE) > 0)
	{
		ln = ft_strjoin(ln, bf);
		if (nl(bf) == 1)
			break ;
	}
	return (ln);
}
