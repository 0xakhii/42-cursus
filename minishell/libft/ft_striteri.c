/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:43:36 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:09 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	index = 0;
	if (!s || !f)
		return ;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
	s[index] = '\0';
}

// void	f(unsigned int i, char *j)
// {
// 	i = 0;
// 	j[i] = 'a';
// 	write(1, &j[i], 1);
// }

// int	main()
// {
// 	char str[] = "hello";
// 	ft_striteri(str, f);
// 	printf("\n");
// }