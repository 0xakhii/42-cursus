/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 02:05:19 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:05:23 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdio.h>
# include<unistd.h>
# include<stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putunsigned(unsigned int c, int *len);
void	ft_putnbr(int c, int *len);
void	ft_puthex_lower(unsigned int c, int *len);
void	ft_putptr(unsigned long c, int *len, int in_first);
void	ft_puthex_upper(unsigned int c, int *len);

#endif