/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:17:34 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:13:46 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include<stdio.h>
int main()
{
    printf("my function: %i\n", ft_isascii('a'));
    printf("my function: %i\n", ft_isascii('5'));
    printf("my function: %i\n", ft_isascii(128));
    return 0;
}
*/