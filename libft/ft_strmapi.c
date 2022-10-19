/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:19:01 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/19 14:32:00 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	func1(unsigned int x, char chr)
{
	(void) x;
	chr = 'a';
	return (chr);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		index;

	char (*func1)(unsigned int, char) = f;
	index = 0;
	if (s == '\0')
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	index = 0;
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = func1(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}

// int main()
// {
// 	char *str = "dsds";
// 	printf("%s\n", ft_strmapi(str, ft));
// }
