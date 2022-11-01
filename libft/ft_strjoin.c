/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:19:36 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:12 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (s1 == '\0' || s2 == '\0')
		return (NULL);
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[index])
	{
		str[index2++] = s1[index];
		index++;
	}
	index = 0;
	while (s2[index])
	{
		str[index2++] = s2[index];
		index++;
	}
	str[index2] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	s1[6] = "hello";
// 	char	s2[7] = " world";

// 	printf("str: %s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
