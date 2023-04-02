/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:20:11 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 15:54:16 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int is_redirect(char c)
{
    return c == '<' || c == '>' || c == '|';
}

int is_quote(char c)
{
    return c == '\'' || c == '\"';
}

int is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

int	is_separator(char c)
{
    return (c == '|' || c == ';');
}
