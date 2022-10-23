/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:43:36 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/23 21:31:39 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		index;

	index = 0;
	if (!s)
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
// 	while (j[i] != '\0')
// 	{
// 		j[i] = 'a';
// 		write(1, &j[i], 1);
// 		i++;
// 	}
// }

// int	main()
// {
// 	char *str = "dsds";

// 	printf("%s\n", ft_striteri(str, f));
// }
