/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:27:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/16 16:58:01 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	i;
	size_t	lendst;
	size_t	srclen;

	index = 0;
	lendst = ft_strlen(dest);
	i = lendst;
	srclen = ft_strlen(src);
	if (size == 0 || size <= lendst)
		return (srclen + size);
	while (src [index] != '\0' && index < size - lendst - 1)
	{
		dest[i] = src[index];
		index++;
		i++;
	}
	dest[i] = '\0';
	return (lendst + srclen);
}
// #include<stdio.h>
// #include<string.h>
// int main()
// {
// 	char dst[13] = "hello";
// 	char dst1[13] = "hello";
// 	const char *src = " world!";
// 	size_t dstsize = ft_strlen(dst) + ft_strlen(src) + 1;
// 	printf("strlcat return: %lu\n", strlcat(dst, src, dstsize));
// 	printf("dst: %s\n", dst);
// 	printf("my function return: %lu\n", ft_strlcat(dst1, src, dstsize));
// 	printf("my function: %s\n", dst);
// 	return 0;
// } 
