/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/29 15:36:10 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	char	**args;

	i = 0;
	if (argc < 2)
			msg_er();
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				if (ft_isdigit(argv[i][j] == 0))
					msg_er();
				j++;
			}
			i++;
		}
		ft_putstr_fd("\033[1;32mOK\n\033[0m", 1);
	}
	return 0;
}
