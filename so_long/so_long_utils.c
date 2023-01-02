/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:22 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/02 00:42:06 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s == NULL)
		return ;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}

void	msg_er(char *msg)
{
	ft_putstr_fd("\033[1;31m[Error]\n\033[0m ", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	msg_ok(char *msg)
{
	ft_putstr_fd("\033[1;32m[OK]\n\033[0m ", 1);
	ft_putstr_fd(msg, 1);
	ft_putstr_fd("\n", 1);
}
