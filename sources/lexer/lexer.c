/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:47:39 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 17:53:37 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


/**
*@brief adds a new token to a linked list of tokens.
*@param tokens is a pointer to a t_token pointer. It is used to keep track of the linked list of tokens.
*@param token is a pointer to a t_token representing a new token to be added to the linked list.
*@return none.
*/
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

/**
*@brief gets a pointer to an "input" character pointer. 
*@param input
*@return It returns a new character pointer containing the substring from the beginning of the "input" string to the first separator or white space character.
*/
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

/**
*@brief This function is responsible for parsing an input string and creating a linked list of tokens, where each token is represented by a t_token object.
*@param input
*@return returns a pointer to an object of type t_token
*/
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