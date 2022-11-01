/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:28:27 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:14:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_n(int count)
{
	int	index;

	index = 0;
	if (count <= 0)
		index++;
	while (count)
	{
		count = count / 10;
		index++;
	}
	return (index);
}

char	*ft_itoa(int n)
{
	int		index;
	int		size;
	char	*str;

	index = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count_n(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n)
	{
		str[size - index++] = ((n % 10) + '0');
		n = n / 10;
	}
	return (str);
}

// int	main()
// {
// 	int n = 5;

// 	printf("%s\n",ft_itoa(n));
// 	system("leaks  a.out");

// }