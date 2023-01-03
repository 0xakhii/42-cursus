/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:41:53 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:29 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	y;

	index = 0;
	if (needle[0] == 0)
		return ((char *)&haystack[index]);
	if (haystack == NULL && len == 0)
		return (NULL);
	while (haystack[index] != '\0')
	{
		y = 0;
		while (haystack[index + y] == needle[y] && index + y < len)
		{
			if (needle[y + 1] == '\0')
				return ((char *)&haystack[index]);
			y++;
		}
		index++;
	}
	return (NULL);
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     char haystack[] = "hey what's up";
//     char tofind[] = "y";
//     printf("strn: %s\n", strnstr(haystack, tofind, 15));
//     printf("ft_n: %s\n", ft_strnstr(haystack, tofind, 15));
// }