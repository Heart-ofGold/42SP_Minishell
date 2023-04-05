/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/05 04:11:53 by mcarecho         ###   ########.fr       */
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
t_token	*append_token(t_token *tokens, t_token *token, t_token *last_token)
{
	t_token	*current;

	current = tokens;
	while (current->next_cmd != NULL && last_token->type != REDIRECT)
		current = current->next_cmd;
	while (last_token->type == REDIRECT && current->next_redirection != NULL)
		current = current->next_redirection;
	if (last_token->type == REDIRECT)
	{
		current->next_redirection = token;
		tokens->n_redirection++;
	}
	else
	{
		current->next_cmd = token;
		if (token->type == WORD)
			tokens->n_cmds++;
	}
	return (token);
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
	!is_pipe((*input[len])) && !is_redirect((*input)[len]))
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
	(*tokens)->n_cmds = 0;
	(*tokens)->n_redirection = 0;
	(*tokens)->next_cmd = NULL;
	(*tokens)->next_redirection = NULL;
	(*tokens)->type = SEPARATOR;
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
	t_token	*tmp;
	int		holder;

	start_tokens(&tokens);
	tmp = tokens;
	holder = is_symbol(*input);
	if (holder == SEPARATOR || holder == PIPE)
		perror("bash: syntax error near unexpected token `|'");
	while (*input)
	{
		holder = is_symbol(*input);
		if (holder == WHITESPACE)
			input++;
		else if (holder == QUOTE)
			input = when_quotes(tokens, &tmp, input);
		else if (holder == SEPARATOR || holder == PIPE)
			input = when_sep_pipe(tokens, &tmp, input, holder);
		else if (holder == REDIRECT)
			input = when_redirect(tokens, &tmp, input);
		else if (holder == WORD)
			input = when_word(tokens, &tmp, input);
	}
	return (normalize(tokens));
}
