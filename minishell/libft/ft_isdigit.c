/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:31:16 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:13:48 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
#include<stdio.h>
int main()
{
    printf("1 :%i\n", ft_isdigit('1'));
    printf("/ :%i\n", ft_isdigit('/'));
    printf("0 :%i\n", ft_isdigit('0'));
    printf("9 :%i\n", ft_isdigit('9'));
    printf("g :%i\n", ft_isdigit('g'));
    return 0;
}
*/
