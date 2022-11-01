/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:45:17 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:15:32 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (0 <= len)
	{
		if (s[len] == (char)c)
			return ((char *)(&s[len]));
		len--;
	}
	return (0);
}

// int main()
// {
// 	printf("strrchr: %s\n", ft_strrchr("hello world", ' '));
// }