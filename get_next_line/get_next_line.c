/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:55:32 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/09 18:16:49 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fd_read(int fd, char *line)
{
	char	*str;
	int		bytes;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(str, '\n')) && bytes != 0)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (str);
			return (NULL);
		}
		str[bytes] = '\0';
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
}
