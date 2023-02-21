/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:19:36 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/18 05:35:18 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_line;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new_line = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_line)
		return (NULL);
	while (s1[i])
	{
		new_line[i2++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		new_line[i2++] = s2[i++];
	new_line[i2] = '\0';
	free(s1);
	return (new_line);
}

// int	main(void)
// {
// 	char	s1[6] = "hello";
// 	char	s2[7] = " world";

// 	printf("str: %s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
