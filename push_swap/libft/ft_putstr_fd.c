/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:36:28 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:59 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s && s[index] != '\0')
	{
		write (fd, &s[index], 1);
		index++;
	}
}

// int main()
// {
// 	char *s = "hello mfs";
// 	int fd = 1;
// 	ft_putstr_fd(s, fd);
// }