/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:29:53 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/05 22:44:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
*@brief creates a token of type REDIRECT with value equal to c and initial and 
*final position equal to pos
*@param c one character
*@param pos a position
*@return a token of type REDIRECT
*/
// t_token	*create_redirect_token(char c, int pos)
// {
// 	t_token	*token;

// 	token = malloc(sizeof(t_token));
// 	token->type = REDIRECT;
// 	token->value = malloc(2 * sizeof(char));
// 	token->value[0] = c;
// 	token->value[1] = '\0';
// 	token->start_pos = pos;
// 	token->end_pos = pos;
// 	return (token);
// }

/**
*@brief creates a token of type PIPE with value equal to "|" and initial and 
*final position equal to pos
*@param pos
*@return a token of type PIPE
*/
// t_token	*create_pipe_token(int pos)
// {
// 	t_token	*token;

// 	token = malloc(sizeof(t_token));
// 	token->type = PIPE;
// 	token->value = malloc(2 * sizeof(char));
// 	token->value[0] = '|';
// 	token->value[1] = '\0';
// 	token->start_pos = pos;
// 	token->end_pos = pos;
// 	return (token);
// }

/**
*@brief takes the input string and two positions: start_pos and end_pos. Creates
*a WORD type token with a value equal to the subset of the input string starting
*at start_pos and ending at end_pos
*@param input
*@param start_pos
*@param end_pos
*@return a token with type WORD, value equal to the sub-char of the input 
*between the positions of start_pos and end_pos
*/
// t_token	*create_word_token(char *input, int start_pos, int end_pos)
// {
// 	t_token	*token;

// 	token = malloc(sizeof(t_token));
// 	token->type = WORD;
// 	token->value = malloc((end_pos - start_pos + 2) * sizeof(char));
// 	strncpy(token->value, &input[start_pos], end_pos - start_pos + 1);
// 	token->value[end_pos - start_pos + 1] = '\0';
// 	token->start_pos = start_pos;
// 	token->end_pos = end_pos;
// 	return (token);
// }

/**
*@brief cover the input string from position pos until it finds a separator 
*(whitespace, redirection or pipe), and creates and returns the respective token
*with the function corresponding to the separation rules
*@param input
*@param pos
*@return the next token found in the string
*/
t_token	*get_next_token(char *input, int end_pos)
{
	while (input[end_pos] != '\0')
	{
		if (is_quote(input[end_pos]))
		{
			end_pos += ft_strchr(&input[end_pos] + 1, input[end_pos])
				- &input [end_pos];
		}
		else if (is_redirect(input[end_pos]) || is_pipe(input[end_pos])
			|| is_separator(input[end_pos]))
		{
			return (n_token(input, WORD, end_pos - 1));
		}
		end_pos++;
	}
	return (n_token(input, WORD, end_pos));
}

/**
*@brief a new token with the type and value specified in the parameters
*@param value
*@param type
*@return takes a value and a type and creates a new token with those values, 
*setting the start and end positions to 0 and the next token to NULL
*/
t_token	*n_token(char *value, int type, int size)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->n_cmds = 0;
	token->n_redirection = 0;
	token->type = type;
	token->value = ft_substr(value, 0, size + 1);
	token->next_cmd = NULL;
	token->next_redirection = NULL;
	return (token);
}
