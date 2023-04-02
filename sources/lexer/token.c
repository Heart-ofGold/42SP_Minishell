/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 06:29:53 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/02 15:57:38 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token *create_redirect_token(char c, int pos)
{
    t_token *token = malloc(sizeof(t_token));
    token->type = REDIRECT;
    token->value = malloc(2 * sizeof(char));
    token->value[0] = c;
    token->value[1] = '\0';
    token->start_pos = pos;
    token->end_pos = pos;
    return token;
}

t_token *create_pipe_token(int pos)
{
    t_token *token = malloc(sizeof(t_token));
    token->type = PIPE;
    token->value = malloc(2 * sizeof(char));
    token->value[0] = '|';
    token->value[1] = '\0';
    token->start_pos = pos;
    token->end_pos = pos;
    return token;
}

t_token *create_word_token(char *input, int start_pos, int end_pos)
{
    t_token *token = malloc(sizeof(t_token));
    token->type = WORD;
    token->value = malloc((end_pos - start_pos + 2) * sizeof(char));
    strncpy(token->value, &input[start_pos], end_pos - start_pos + 1);
    token->value[end_pos - start_pos + 1] = '\0';
    token->start_pos = start_pos;
    token->end_pos = end_pos;
    return token;
}

t_token *get_next_token(char *input, int *pos)
{
    int start_pos = *pos;
    int end_pos = *pos;
    t_token *token = NULL;

    while (input[*pos] != '\0')
    {
        if (is_whitespace(input[*pos]))
        {
            end_pos = *pos - 1;
            break;
        }
        else if (is_redirect(input[*pos]))
        {
            token = create_redirect_token(input[*pos], *pos);
            *pos = *pos + 1;
            return token;
        }
        else if (input[*pos] == '|')
        {
            token = create_pipe_token(*pos);
            *pos = *pos + 1;
            return token;
        }
        else
        {
            end_pos = *pos;
            *pos = *pos + 1;
        }
    }
    if (input[*pos] == '\0')
    {
        end_pos = *pos - 1;
    }
    token = create_word_token(input, start_pos, end_pos);

    return token;
}

t_token	*new_token(char *value, int type)
{
	t_token *token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = ft_strdup(value);
	token->start_pos = 0;
	token->end_pos = 0;
	token->next = NULL;
	return (token);
}
