/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:29:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/10/15 17:50:31 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == 32 || (str[index] > 8 && str[index] < 14))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - '0');
		index++;
	}
	res = res * sign;
	return (res);
}
// int main()
// {
//     char str[40] = "\n   \t\r  \v\f    -04as65-45654654";
//     printf("ft_a: %i\n", ft_atoi(str));
//     printf("atoi: %i\n", atoi(str));
// }