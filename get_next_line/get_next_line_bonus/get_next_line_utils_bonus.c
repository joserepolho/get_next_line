/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:15:56 by joaoribe          #+#    #+#             */
/*   Updated: 2023/03/26 14:19:00 by joaoribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*substr;

	i = start;
	k = ft_strlen(s);
	j = 0;
	if (i >= k)
		len = 0;
	else if (len > (k - i))
		len = k - i;
	substr = (char *)malloc(len + 1);
	if (!s || !substr)
		return (0);
	while (i < k && j < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bf;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	bf = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!bf || !s1 || !s2)
		return (0);
	while (s1[i])
	{
		bf[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		bf[i + j] = s2[j];
		j++;
	}
	bf[i + j] = '\0';
	return (bf);
}
