/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 07:07:51 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
			token = new_token(*input, SEPARATOR);
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