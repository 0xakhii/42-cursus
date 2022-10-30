/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:01:54 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/30 08:47:30 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wrd_cnt(char const *s, char del)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
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
	int		i;
	int		j;
	int		k;
	int		l;
	char	**str;

	l = wrd_cnt(s, c);
	i = 0;
	k = 0;
	str = (char **)malloc((wrd_cnt(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (k < l)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[k] = ft_substr(s, j, i - j);
		k++;
	}
	str[k] = NULL;
	return (str);
}

// #include<stdio.h>
// int	main()
// {
// 	char	str[] = "        J FE MAR APRI MAY JUN JULY AUG 
//	SEPTEMBER OCTOB NOVEMB DEC ";
// 	char **A = ft_split(str, ' ');
// 	int	i = 0;
// 	while (i < 12)
// 	{
// 		printf("%s\n", A[i]);
// 		i++;
// 	}
// 	system("leaks a.out");
// }