/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:57:15 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/24 04:06:44 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (s1[0] == '\0' || set[0] == '\0')
		return (NULL);
	trim = malloc(((ft_strlen(s1) - ft_strlen(set)) + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	while (s1[index])
	{
		if (s1[index] == set[index])
		{
			trim[index2] = s1[index];
			index2++;
		}
		while (s1[index] != set[index])
		{
			index++;
		}
		index++;
		index2++;
	}
	return (trim);
}

// int main()
// {
// 	const char s1[] = "123hello world321";
// 	const char set[] = "231";
// 	printf("%s\n", ft_strtrim(s1, set));
// 	return 0;
// }