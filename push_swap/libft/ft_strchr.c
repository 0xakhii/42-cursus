/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 19:56:18 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:02 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(s);
	while (index <= len)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)(&s[index]));
		index++;
	}
	return (0);
}

// int main ()
// {
// 	char str[] = "hello there";
// 	printf("str: %s\n", strchr(str, '\0'));
// 	printf("ft_: %s\n", ft_strchr(str, '\0'));
// 	return 0;
// }