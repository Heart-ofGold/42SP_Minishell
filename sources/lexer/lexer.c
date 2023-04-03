/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 23:45:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
*@brief adds a new token to a linked list of tokens.
*@param tokens is a pointer to a t_token pointer. It is used to keep track of 
*the linked list of tokens.
*@param token is a pointer to a t_token representing a new token to be added 
*to the linked list.
*@return none.
*/
void	append_token(t_token **tokens, t_token *token)
{
	t_token	*current;

	if ((*tokens)->value == NULL)
		*tokens = token;
	else
	{
		current = *tokens;
		while (current->next != NULL)
			current = current->next;
		current->next = token;
	}
}

/**
*@brief gets a pointer to an "input" character pointer. 
*@param input
*@return It returns a new character pointer containing the substring from the 
*beginning of the "input" string to the first separator or white space character
*/
char	*get_value(char **input)
{
	char	*value;
	int		len;

	len = 0;
	while ((*input)[len] && !is_separator((*input)[len]) &&
		!is_whitespace((*input)[len]) && !is_pipe((*input)[len]) &&
		!is_redirect((*input)[len]))
		len++;
	if (is_whitespace((*input)[len]))
		len++;
	value = malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	ft_strlcpy(value, *input, len + 1);
	*input += len;
	return (value);
}

void	start_tokens(t_token **tokens)
{
	*tokens = malloc(sizeof(t_token));
	(*tokens)->value = NULL;
	(*tokens)->start_pos = 0;
	(*tokens)->end_pos = 0;
	(*tokens)->n_cmds = 1;
	(*tokens)->next = NULL;
	(*tokens)->type = 0;
}

int	is_symbol(char c)
{
	if (is_separator(c))
		return (SEPARATOR);
	else if (is_redirect(c))
		return (REDIRECT);
	else if (is_pipe(c))
		return (PIPE);
	else if (is_quote(c))
		return (QUOTE);
	else if (is_whitespace(c))
		return (WHITESPACE);
	else
		return (WORD);
}

/**
*@brief This function is responsible for parsing an input string and creating a 
*linked list of tokens, where each token is represented by a t_token object.
*@param input
*@return returns a pointer to an object of type t_token
*/
t_token	*lexer(char *input)
{
	t_token	*tokens;
	char	*value;
	int		holder;

	start_tokens(&tokens);
	while (*input)
	{
		holder = is_symbol(*input);
		if (holder == WHITESPACE)
			input++;
		else if (holder == SEPARATOR || holder == REDIRECT || holder == PIPE
			|| holder == QUOTE)
		{
			append_token(&tokens, new_token(input, holder));
			input++;
			tokens->n_cmds += 1;
		}
		else
		{
			value = get_value(&input);
			append_token(&tokens, new_token(value, WORD));
			free(value);
		}
	}
	return (tokens);
}
