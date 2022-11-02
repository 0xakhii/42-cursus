/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:15:16 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/02 16:40:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdio.h>
# include<unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putunbr(unsigned int c);
void	ft_putstr(char *str);
void	ft_putnbr(int c);
void	ft_putchar(char c);

#endif