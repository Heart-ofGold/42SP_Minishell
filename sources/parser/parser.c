/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/04 22:27:04 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strdup_char(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

t_parser	*start_parser(t_token *token)
{
	int			i;
	t_parser	*parser;

	i = 0;
	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return (NULL);
	parser->cmd = (char ***)malloc(sizeof(char **) * token->n_cmds + 1);
	if (!parser->cmd)
		return (NULL);
	while (i < token->n_cmds)
	{
		parser->cmd[i] = (char **)malloc(sizeof(char *) * token->n_cmds + 1);
		if (!parser->cmd[i])
			return (NULL);
		i++;
	}
	parser->i = 0;
	parser->n_cmds = 0;
	return (parser);
}

t_parser	*parsing(t_token *token)
{
	t_parser	*parser;
	int			index;

	index = 0;
	parser = start_parser(token);
	if (!token->next_cmd)
		return (one_cmd(token));
	while (token->next_cmd)
	{
		if (token->type == WORD)
		{
			parser->cmd[parser->i] = ft_split_pipex(token->value);
			index++;
		}
		else if (token->type == !WORD)
		{
			index = 0;
			parser->n_cmds++;
			parser->i++;
		}
		token = token->next_cmd;
	}
	last_node(parser, token, parser->i, index);
	return (parser);
}
