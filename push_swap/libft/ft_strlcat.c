/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:27:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:14 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	i = dstlen;
	srclen = ft_strlen(src);
	if (!dst && srclen == 0)
		return (dstlen + dstsize);
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	while (src [index] != '\0' && index < dstsize - dstlen - 1)
	{
		dst[i] = src[index];
		index++;
		i++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}

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