/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:21 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/09 18:55:03 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_line;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_line = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_line)
		return (NULL);
	while (s1[index])
	{
		new_line[index2++] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		new_line[index2++] = s2[index];
		index++;
	}
	new_line[index2] = '\0';
	return (new_line);
}

char	*ft_strchr(char *s, int c)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(s);
	while (index <= len)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)(&s[index]));
		index++;
	}
	return (0);
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
