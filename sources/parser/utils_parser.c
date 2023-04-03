/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:21:49 by feralves          #+#    #+#             */
/*   Updated: 2023/04/03 19:33:42 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parser	*one_cmd(t_token *token)
{
	t_parser	*parser;

	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->cmd = (char ***)malloc(sizeof(char **));
	if (!parser->cmd)
		return (NULL);
	parser->cmd[0] = (char **)malloc(sizeof(char *));
	if (!parser->cmd[0])
		return (NULL);
	parser->n_cmds = 0;
	parser->cmd[0][0] = token->value;
	return (parser);
}

void	last_node(t_parser *parser, t_token *token, int index, int j)
{
	while (token)
	{
		parser->cmd[index][j] = token->value;
		token = token->next;
	}
	index++;
	parser->cmd[index][0] = NULL;
}
