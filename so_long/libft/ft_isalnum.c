/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:41:50 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:13:41 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include<stdio.h>
int main()
{
    printf("A :%i\n", ft_isalnum('A'));
    printf("a :%i\n", ft_isalnum('a'));
    printf("Z :%i\n", ft_isalnum('Z'));
    printf("z :%i\n", ft_isalnum('z'));
    printf("0 :%i\n", ft_isalnum('0'));
    printf("9 :%i\n", ft_isalnum('9'));
    printf("/ :%i\n", ft_isalnum('/'));
    printf("* :%i\n", ft_isalnum('*'));
    return 0;
}
*/
