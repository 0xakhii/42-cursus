/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:01:34 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/10 23:01:34 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		ptr = ft_lstlast(*lst);
		ptr -> next = new;
	}
}
