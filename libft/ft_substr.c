/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:11:07 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/23 20:40:55 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	index;
	size_t	lenght;

	if (!s)
		return (0);
	lenght = ft_strlen(s);
	if (start >= lenght)
	{
		sstr = malloc(1);
		sstr[0] = '\0';
		return (sstr);
	}
	sstr = malloc(len + 1);
	if (sstr == 0)
		return (0);
	index = 0;
	while (index < len)
	{
		sstr[index] = s[start];
		index++;
		start++;
	}
	sstr[index] = '\0';
	return (sstr);
}

// int	main(void)
// {
// 	const char		*s;
// 	unsigned int	start;
// 	size_t			len;

// 	s = "i just want this part #############";
// 	start = 5;
// 	len = 20;
// 	printf("%s\n", ft_substr(s, start, len));
// 	return (0);
// }