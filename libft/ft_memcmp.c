/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:13:15 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	int				diff;

	diff = 0;
	index = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (index < n)
	{
		diff = tmp1[index] - tmp2[index];
		if (tmp1[index] != tmp2[index])
			return (diff);
		index++;
	}
	return (0);
}
// int main()
// {
//     printf("mem: %i\n", memcmp("abcdefghij", "abcdefgxyz", 7));
//     printf("ft_: %i\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
//     return 0;
// }
