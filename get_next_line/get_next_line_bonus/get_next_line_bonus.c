/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:39:13 by joaoribe          #+#    #+#             */
/*   Updated: 2023/03/26 14:14:18 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	bf_to_str(int fd, char *bf, char **str)
{
	int		i;
	char	*tmp;

	i = read(fd, bf, BUFFER_SIZE);
	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		while (i > 0)
		{
			bf[i] = 0;
			if (!str[fd])
			    str[fd] = ft_substr(bf, 0, i);
			else
			{
				tmp = str[fd];
				free(tmp);
				str[fd] = ft_strjoin(str[fd], bf);
			}
			if (ft_strchr(bf, '\n'))
				break ;
		}
	}
	free(bf);
}

static char	*process(int fd, char **str)
{
	int		i;
	int		j;
	char	*fnl;
	char	*tmp;

	i = ft_strlen(str[fd]);
	j = ft_strlen(ft_strchr(str[fd], '\n'));
	if (!str[fd])
		return (0);
	if (!ft_strchr(str[fd], '\n'))
	{
		fnl = ft_substr(str[fd], 0, i);
		free(str[fd]);
		str[fd] = 0;
		return (fnl);
	}
	fnl = ft_substr(str[fd], 0, i - j + 1);
	tmp = str[fd];
	str[fd] = ft_substr(str[fd], j, i - j - 1);
	free(tmp);
	return (fnl);
}					

char	*get_next_line(int fd)
{
	char		*bf;
	static char	*str[OPEN_MAX];

	bf = malloc(BUFFER_SIZE + 1);
	if (!bf)
		return (0);
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, bf, BUFFER_SIZE) < 0)
	{
		free (bf);
		return (0);
	}
	bf_to_str(fd, bf, str);
	return (process(fd, str));
}
