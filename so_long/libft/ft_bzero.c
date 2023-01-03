/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 05:21:15 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:13:36 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			index;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		tmp[index] = 0;
		index++;
	}
}
//  #include<stdio.h>
//  #include<string.h>
//  int main()
//  {
//      char s1[6] = "hello";
//      char s[6] = "hello";
//      bzero(s1, 2);
//      printf("bzero: %s\n", s1);
//      bzero(s, 2);
//      printf("ft_bzero: %s\n", s);
//      return 0;
// }
