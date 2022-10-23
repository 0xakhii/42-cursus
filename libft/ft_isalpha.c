/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:22:51 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/23 20:39:40 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
 #include<stdio.h>
 int main()
 {
     printf("Z: %i\n", ft_isalpha('Z'));
     printf("A: %i\n", ft_isalpha('A'));
     printf("a: %i\n", ft_isalpha('a'));
     printf("z: %i\n", ft_isalpha('z'));
     printf("5: %i\n", ft_isalpha('5'));
     return 0;
 }*/