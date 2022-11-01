/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 23:29:08 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:51 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
// 	 int fd = open("file.txt", O_WRONLY);
// 	 printf("%d\n", fd);
// 	 char str[] = "";
// 	ft_putchar_fd('a', fd);
// }