/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:42:56 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/25 19:48:21 by ojamal           ###   ########.fr       */
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

int is_empty(t_list *lexer)
{
    char *str;
    while (lexer)
    {
        str = lexer->content;
        if (str[0] != ' ' && str[0] != '\t')
            return (0);
        lexer = lexer->next;
    }
    return (1);
}

int quote_check(t_list *lexer)
{
    int singleQuoteOpen = 0;
    int doubleQuoteOpen = 0;

    while (lexer)
    {
        char *str = lexer->content;
        int i = 0;

        while (str[i])
        {
            if (str[i] == '\'')
                singleQuoteOpen = !singleQuoteOpen;

            if (str[i] == '\"')
                doubleQuoteOpen = !doubleQuoteOpen;

            i++;
        }

        lexer = lexer->next;
    }

    if (singleQuoteOpen || doubleQuoteOpen)
        return 1;

    return 0;
}

t_list *lexer_init(char *in)
{
    int i;
    char *str;
    t_list *lexer;

    lexer = NULL;
    i = 0;
    while (1)
    {
        if (in[i] == '\0')
            break;
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
                }
                else if (in[i] == '|')
                {
                    str = malloc(2);
                    str[0] = '|';
                    str[1] = '\0';
                    i++;
                }
                else
                {
                    str = malloc(2);
                    str[0] = in[i];
                    str[1] = '\0';
                    i++;
                }
                ft_lstadd_back(&lexer, ft_lstnew(str));
            }
            if (quote_check(lexer))
            {
                printf("quote error\n");
                break;
            }
            if (is_empty(lexer))
            {
                // printf("empty error\n");
                break;
            }
        }
    }
    return (lexer);
}

int	main(void)
{
    t_list *lexer;
    char *in;

    lexer = NULL;
    while (1)
    {
        in = readline("minishell$>");
        lexer = lexer_init(in);
        printing(lexer);
    }
}
