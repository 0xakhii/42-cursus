/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:26:46 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/24 09:51:06 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 1;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

// #include<stdio.h>
// int main()
// {
// 	char *str = "123hel123lo123";
// 	printf("the size of '%s' is: %zu\n",str, ft_strlen(str));
// 	return 0;
// }
