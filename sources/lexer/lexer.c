/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 16:03:59 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	append_token(t_token **tokens, t_token *token)
{
	if (*tokens == NULL)
	{
		*tokens = token;
	}
	else
	{
		t_token *current = *tokens;
		while (current->next != NULL)
			current = current->next;
		current->next = token;
	}
}

char	*get_value(char **input)
{
	char	*value;
	int		len;

	len = 0;
	while ((*input)[len] && !is_separator((*input)[len]) && !is_whitespace((*input)[len]))
		len++;
	value = malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, *input, len + 1);
	*input += len;
	return (value);
}

t_token	*lexer(char *input)
{
	t_token	*tokens;
	t_token	*token;

	tokens = NULL;
	while (*input)
	{
		if (is_whitespace(*input))
			input++;
		else if (*input == '|' || *input == ';')
		{
			token = new_token(input, SEPARATOR);
			input++;
			append_token(&tokens, token);
		}
		else
		{
			char *value = get_value(&input);
			token = new_token(value, WORD);
			append_token(&tokens, token);
			free(value);
		}
	}
	return (tokens);
}

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%d] %s\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
}