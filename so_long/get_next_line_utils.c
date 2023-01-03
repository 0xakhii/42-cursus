/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:21 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/03 22:05:55 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	f_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*new_line;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new_line = malloc(f_strlen(s1) + f_strlen(s2) + 1);
	if (!new_line)
		return (NULL);
	while (s1[i])
	{
		new_line[i2++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		new_line[i2++] = s2[i++];
	new_line[i2] = '\0';
	free(s1);
	return (new_line);
}

char	*f_strchr(char *s, char c)
{
	int	i;
	int	len;

	if (!s)
		return (0);
	i = 0;
	len = f_strlen(s);
	while (i <= len)
	{
		if (s[i] == c)
			return ((&s[i]));
		i++;
	}
	return (0);
}

char	*get_first_line(char *next_line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!*next_line)
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\n')
		i++;
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		new_line[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
	{
		new_line[i] = next_line[i];
		i++;
	}
	return (new_line[i] = '\0', new_line);
}

char	*get_new_line(char *str)
{
	int		i;
	int		i2;
	char	*new_line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_line = (char *)malloc(f_strlen(str) - i);
	if (!new_line)
		return (NULL);
	i++;
	i2 = 0;
	while (str[i])
		new_line[i2++] = str[i++];
	new_line[i2] = '\0';
	free(str);
	return (new_line);
}
