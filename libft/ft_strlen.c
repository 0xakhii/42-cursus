/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:26:46 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:21 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
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
