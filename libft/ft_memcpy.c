/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 04:49:42 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:44 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned int	index;

	index = 0;
	if (dst == src)
		return (dst);
	if (src == 0 && dst == 0)
		return (0);
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	while (index < n)
	{
		tmpdst[index] = tmpsrc[index];
		index++;
	}
	return (dst);
}
// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char s[] = "hello";
// 	char s1[] = "there there";
// 	char b[] = "hello";
// 	char b1[] = "there there";
// 	printf("memcpy: %s\n", memcpy(s1, s, 8));
// 	printf("ft_memcpy: %s\n", ft_memcpy(b1, b, 8));
// }
