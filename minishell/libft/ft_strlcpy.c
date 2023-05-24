/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:24:47 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:16 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	srcsize;

	index = 0;
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[index] != '\0' && index < dstsize - 1)
		{
			dst[index] = src[index];
			index++;
		}
	dst[index] = '\0';
	}
	return (srcsize);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char strsrc[] = "BBBB";
//     char strdst[0XF00];
//     char strdst1[0XF00];
//     // strlcpy(strdst, strsrc, sizeof(strdst));
//     printf("strlcpy: %s\n", strdst);
//     printf("%lu\n", strlcpy(strdst, strsrc, sizeof(strdst)));
//     // ft_strlcpy(strdst1, strsrc, 2);
//     printf("ft_strlpy: %s\n", strdst1);
//     printf("%zu\n", ft_strlcpy(strdst1, strsrc, sizeof(strdst1)));
//     return 0;
// }
