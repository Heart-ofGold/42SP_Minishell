/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:50:19 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/05 04:12:57 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*when_quotes(t_token	*tokens, t_token **tmp, char *input)
{
	char	*value;

	value = NULL;
	value = ft_strchr(input + 1, *input);
	*tmp = append_token(tokens, n_token(input, WORD, value - input + 1),*tmp);
	return (input + ft_strlen((*tmp)->value));
}

char	*when_redirect(t_token *tokens, t_token **tmp, char *input)
{
	if (input[1] == *input)
		*tmp = append_token(tokens, n_token(input, WORD, 2), *tmp);
	else
	{
		*tmp = append_token(tokens, n_token(input, WORD, 1), *tmp);
	}
	return (input + ft_strlen((*tmp)->value));
}

char	*when_sep_pipe(t_token *tokens, t_token **tmp, char *input, int holder)
{
	*tmp = append_token(tokens, n_token(input, holder, 1), *tmp);
	input++;
	return (input);
}

char	*when_word(t_token *tokens, t_token **tmp, char *input)
{
	*tmp = append_token(tokens, get_next_token(input, 0), *tmp);
	return (input + ft_strlen((*tmp)->value));
}

t_token	*normalize(t_token *token)
{
	t_token	*tmp;

	token->next_cmd->next_redirection = token->next_redirection;
	tmp = token->next_cmd;
	tmp->n_cmds = token->n_cmds;
	tmp->n_redirection = token->n_redirection;
	free(token);
	return (tmp);
}
