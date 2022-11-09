/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:21 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/09 07:23:53 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
