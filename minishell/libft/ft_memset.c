/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 02:19:37 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:49 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		tmp[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char str[10] = "hello";
// 	char str1[10] = "hello";
// 	printf("memset: %s\n", memset(str, '@', 2));
// 	printf("ft_memset: %s\n", ft_memset(str1, '@', 2));
// 	return 0;
// }
