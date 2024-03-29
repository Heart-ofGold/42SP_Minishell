/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/15 19:38:45 by feralves         ###   ########.fr       */
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
t_token	*append_token(t_global *g, t_token *token, t_token *last_token)
{
	t_token	*current;

	current = g->h_token;
	while (current->next_token != NULL && last_token->type != REDIRECT)
		current = current->next_token;
	current->next_token = token;
	if (token->type == WORD && last_token->type != REDIRECT)
		g->h_token->n_cmds++;
	g->exit_status = verify_unexpecte_token(token, last_token);
	g->h_token->n_tokens++;
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
	(*tokens)->n_tokens = 0;
	(*tokens)->path = NULL;
	(*tokens)->next_token = NULL;
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
void	lexer(char *input, t_global *g)
{
	t_token	*tmp;
	int		holder;

	start_tokens(&g->h_token);
	tmp = g->h_token;
	holder = is_symbol(*input);
	while (*input)
	{
		if (g->exit_status != 0)
			return (error_handler(g));
		holder = is_symbol(*input);
		if (holder == WHITESPACE)
			input++;
		else if (holder == QUOTE)
			input = when_quotes(g, &tmp, input);
		else if (holder == SEPARATOR || holder == PIPE)
			input = when_sep_pipe(g, &tmp, input, holder);
		else if (holder == REDIRECT)
			input = when_redirect(g, &tmp, input);
		else if (holder == WORD)
			input = when_word(g, &tmp, input);
	}
	normalize(g);
}
