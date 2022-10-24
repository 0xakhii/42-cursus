/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:12:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/24 09:25:56 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}
// int main()
// {
// 	//char	str[] = "Hello ";
// 	char *ptr;
// 	ptr = (char *)malloc(6 * sizeof(char));	
// 	for (int x = 0;x <= 6;x++)
// 		printf("ptr[%d] --> %d\n", x, ptr[x]);
// }