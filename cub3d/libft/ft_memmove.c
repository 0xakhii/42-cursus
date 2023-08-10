/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:29:55 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:46 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;
	unsigned char	*dest;
	unsigned char	*srcc;

	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	index = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		while (index <= len)
		{
			dest[len - index] = srcc[len - index];
			index++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

// int main(void)
// {
// 	char str[] = "thanks to @apellicc for this test !\r\n";
// 	char dst[100];
// 	char dst1[100];
// 	printf("mem: %s\n", memmove(dst, str, sizeof(str)));
// 	printf("ft_: %s\n", ft_memmove(dst1, str, sizeof(str)));
// 	for (int i  = 0; i< 20; i++)
// 		printf("*");
// 	printf("\n");
// 	// for (int x  = 0; x< 5; x++)
// 	// 	printf("%", &str[x]);
// 	return (0);
// }