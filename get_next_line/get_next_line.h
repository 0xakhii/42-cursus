/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:56:51 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/17 22:53:46 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21474836414
# endif

char	*get_next_line(int fd);
char	*get_first_line(char *next_line);
char	*get_new_line(char *str);
int		f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(char *s, char c);
char	*fd_read(int fd, char *line);

#endif