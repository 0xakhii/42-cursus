/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:01:54 by osizeamal         #+#    #+#             */
/*   Updated: 2022/11/01 23:13:30 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_word(char const *s, char del)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
	{
		while (s[index] == del)
			index++;
		if (s[index] != '\0')
			count++;
		while (s[index] != del && s[index] != '\0')
			index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	int		size;
	int		index2;
	int		lenght;
	char	**str;

	lenght = len_word(s, c);
	index = 0;
	index2 = 0;
	str = (char **)malloc((len_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (index2 < lenght)
	{
		while (s[index] == c && s[index] != '\0')
			index++;
		size = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		str[index2++] = ft_substr(s, size, index - size);
	}
	str[index2] = NULL;
	return (str);
}

// #include<stdio.h>
// int	main()
// {
// 	char	str[] = "hehe hehe hehe hehe";
// 	char **A = ft_split(str, ' ');
// 	int	index = 0;
// 	while (index < 5)
// 	{
// 		printf("%s\n", A[index]);
// 		index++;
// 	}
// }