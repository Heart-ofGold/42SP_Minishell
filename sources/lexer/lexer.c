/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 17:48:46 by feralves         ###   ########.fr       */
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
	(*tokens)->n_cmds = 0;
	(*tokens)->next = NULL;
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
	t_token	*token;
	char	*value;

	start_tokens(&tokens);
	while (*input)
	{
		if (is_whitespace(*input))
			input++;
		else if (is_separator(*input))
		{
			token = new_token(input, SEPARATOR);
			input++;
			tokens->n_cmds++;
			append_token(&tokens, token);
		}
		else if (is_redirect(*input))
		{
			token = new_token(input, REDIRECT);
			input++;
			tokens->n_cmds++;
			append_token(&tokens, token);
		}
		else if (is_pipe(*input))
		{
			token = new_token(input, PIPE);
			input++;
			tokens->n_cmds++;
			append_token(&tokens, token);
		}
		else
		{
			value = get_value(&input);
			token = new_token(value, WORD);
			tokens->n_cmds++;
			append_token(&tokens, token);
			free(value);
		}
	}
	return (tokens);
}
