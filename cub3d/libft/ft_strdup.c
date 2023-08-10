/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:09:26 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:06 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*s;

	s = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}

// int	main(void)
// {
// 	const char	*s1;

// 	s1 = "";
// 	printf("str: %s\n", strdup(s1));
// 	printf("ft_: %s\n", ft_strdup(s1));
// }