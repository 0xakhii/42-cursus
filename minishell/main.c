/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:42:56 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/23 23:47:51 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *add_characthers(char *str, char x)
{
    char *new_str;
    int i = 0;
    if (str == NULL)
    {
        new_str = malloc(2);
        new_str[0] = x;
        new_str[1] = '\0'; 
    }
    else
    {
        new_str = malloc(ft_strlen(str) + 2);
        while (str[i])
        {
            new_str[i] = str[i];
            i++;
        }
        new_str[i] = x;
        new_str[i + 1] = '\0';
    }
    return (new_str);
}

void    quote_check(t_list *lexer)
{
    int i = 0;
    int j = 0;
    char *str;
    while (lexer)
    {
        str = lexer->content;
        while (str[i])
        {
            if (str[i] == '\'' || str[i] == '\"')
                j++;
            i++;
        }
        if (j % 2 != 0)
        {
            printf("Error: quote not closed\n");
            exit(1);
        }
        j = 0;
        i = 0;
        lexer = lexer->next;
    }
}

int	main(void)
{
    t_list *lexer;
    char *in;
    char *str;

    lexer = NULL;
    while (1)
    {
        in = readline("minishell-> ");
        //printf("%s\n", in);
        int i = 0;
        while (1)
        {
            if (in[i] == '\0')
                break;
            //int j = 0;
            while (in[i])
            {
                str = NULL;
                if (ft_isalpha(in[i]) || in[i] == ' ' || in[i] == '\t')
                {
                    while (in[i] && (ft_isalpha(in[i]) || in[i] == ' ' || in[i] == '\t'))
                    {
                        str = add_characthers(str, in[i]);
                        i++;
                    }
                   ft_lstadd_back(&lexer, ft_lstnew(str));
                   //j = i;
                    //printf("%s -> have len: %d\n", str, j);
                }
                else
                {
                    if (in[i] == '<')
                    {
                        if (in[i + 1] == '<')
                        {
                            str = malloc(3);
                            str[0] = '<';
                            str[1] = '<';
                            str[2] = '\0';
                            i += 2;
                        }
                        else
                        {
                            str = malloc(2);
                            str[0] = '<';
                            str[1] = '\0';
                            i++;
                        }
                        //printf("%s\n", str);
                    }
                    else if (in[i] == '>')
                    {
                        if (in[i + 1] == '>')
                        {
                            str= malloc(3);
                            str[0] = '>';
                            str[1] = '>';
                            str[2] = '\0';
                            i+=2;
                        }
                        else
                        {
                            str = malloc(2);
                            str[0] = '>';
                            str[1] = '\0';
                            i++;
                        }
                        //printf("%s\n", str);
                    }
                    else if (in[i] == '|')
                    {
                        str = malloc(2);
                        str[0] = '|';
                        str[1] = '\0';
                        i++;
                        //printf("%s\n", str);
                    }
                    ft_lstadd_back(&lexer, ft_lstnew(str));
                }
            }
            while (lexer)
            {
                printf("%s\n", lexer->content);
                lexer = lexer->next;
            }
        }
    }
}