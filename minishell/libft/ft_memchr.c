/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 19:56:08 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:40 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*tmp;

	index = 0;
	tmp = (unsigned char *)s;
	while (index < n)
	{
		if (tmp[index] == (unsigned char)c)
			return ((void *)&tmp[index]);
		index++;
	}
	return (NULL);
}
// int main()
// {
//     char str[] = "hey what's up";
//     printf("mem: %s\n", memchr(str,'e', 6));
//     printf("ft_: %s\n", ft_memchr(str, 'e', 6));
//     return 0;
// }
