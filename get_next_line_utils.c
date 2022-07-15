/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dofranci <dofranci@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 22:35:15 by dofranci          #+#    #+#             */
/*   Updated: 2022/07/14 21:35:01 by dofranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if ((char)c == '\0')
		return (0);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	int		x;
	int		y;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	x = -1;
	while (s1[++x] != '\0')
		dst[x] = s1[x];
	y = -1;
	while (s2[++y] != '\0')
		dst[x + y] = s2[y];
	dst[x + y] = '\0';
	free(s1);
	return (dst);
}
