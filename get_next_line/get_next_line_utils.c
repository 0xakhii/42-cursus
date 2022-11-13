/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:21 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/13 22:29:17 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i++] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*get_first_line(char *next_line)
{
	int		index;
	char	*new_line;

	index = 0;
	if (!next_line)
		return (NULL);
	index = ft_strlen(next_line) + 2;
	new_line = (char *)malloc(index);
	if (!new_line)
		return (NULL);
	index = 0;
	while (next_line[index] && next_line[index] != '\n')
	{
		new_line[index] = next_line[index];
		index++;
	}
	if (next_line[index] == '\n')
	{
		new_line[index] = next_line[index];
		index++;
	}
	new_line[index] = '\0';
	return (new_line);
}

char	*get_new_line(char *str)
{
	int		index;
	int		index2;
	char	*new_line;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	new_line = (char *)malloc(ft_strlen(str) - index + 1);
	if (!new_line)
		return (NULL);
	index++;
	index2 = 0;
	while (str[index])
		new_line[index2++] = str[index++];
	new_line[index2] = '\0';
	free(str);
	return (new_line);
}
