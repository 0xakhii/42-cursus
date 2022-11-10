/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:32 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/10 01:27:41 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fd_read(int fd, char *line)
{
	char	*str;
	int		bytes_readed;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	bytes_readed = 1;
	while (!(ft_strchr(str, '\n')) && bytes_readed != 0)
	{
		bytes_readed = read(fd, str, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free (str);
			return (NULL);
		}
		str[bytes_readed] = '\0';
		line = ft_strjoin(line, str);
	}
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = fd_read(fd, str);
	if (!str)
		return (NULL);
	line = get_first_line(str);
	str = get_new_line(str);
	return (line);
}
