/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:16:52 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/15 21:30:36 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_stock(int fd, char *str)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!(f_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free (buff);
			if (str)
				free (str);
			return (NULL);
		}
		buff[i] = '\0';
		str = f_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = get_stock(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = get_first_line(str[fd]);
	str[fd] = get_new_line(str[fd]);
	return (line);
}
