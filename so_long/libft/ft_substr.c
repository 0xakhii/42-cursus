/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 22:11:07 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/02 16:45:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lenght;

	if (s == NULL)
		return (NULL);
	lenght = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (lenght - start >= len)
		str = malloc ((len + 1));
	else
		str = malloc ((lenght - start + 1));
	if (str == NULL)
		return (NULL);
	if (len >= SIZE_MAX)
		ft_strlcpy(str, &s[start], lenght +1);
	else
		ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_substr("hola", 1, 2));
// 	printf("%s\n", ft_substr("hola", 0, 1844674407370955161));
// 	printf("%s\n", ft_substr("tripouille", 0, 42000));
// 	return (0);
// }