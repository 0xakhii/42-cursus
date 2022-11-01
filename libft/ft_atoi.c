/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:29:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/01 23:13:33 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				index;
	int				sign;
	unsigned long	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == 32 || (str[index] > 8 && str[index] < 14))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			sign = sign * -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - '0');
		index++;
	}
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	if (res > 9223372036854775807 && sign == -1)
		return (0);
	return (res * sign);
}
// int main()
// {
//     char str[40] = "-9223372036854775807";
//     printf("ft_a: %i\n", ft_atoi(str));
//     printf("atoi: %i\n", atoi(str));
// }