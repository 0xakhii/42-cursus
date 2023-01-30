/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:19:01 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:24 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	index = 0;
	if (!s)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	index = 0;
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}

// char f(unsigned int i, char j)
// {
// 	j =  j + i;
// 	return j;
// }
// int main()
// {
// 	char *str = "01234";
// 	printf("%s\n", ft_strmapi(str, f));
// }
