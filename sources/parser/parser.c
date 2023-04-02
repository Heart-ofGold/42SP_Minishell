/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 17:45:21 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	test_parser(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (parser->cmd[i])
	{
		while (parser->cmd[i][j])
		{
			ft_printf("%s\n", parser->cmd[i][j]);
			j++;
		}
		i++;
	}
}

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

void	start_parser(t_parser *parser, t_token *token)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		parser->cmd[i] = (char **)malloc(sizeof(char *) * token->n_cmds);
		if (!parser->cmd[i])
			return ;
		i++;
	}
}

void	parsing(t_token *token)
{
	t_parser	*parser;
	int			index;
	int			cmd_index;

	index = 0;
	cmd_index = 0;
	parser = (t_parser *)malloc(sizeof(t_parser));
	if (!parser)
		return ;
	start_parser(parser, token);
	while (token)
	{
		if (token->type == WORD)
		{
			parser->cmd[cmd_index][index] = ft_strdup(token->value);
			index++;
		}
		else if (token->type == PIPE)
		{
			index = 0;
			parser->cmd[cmd_index++][index] = ft_strdup_char(token->value[0]);
			cmd_index++;
		}
		else if (token->type == REDIRECT)
		{
			index = 0;
			parser->cmd[cmd_index++][index] = ft_strdup_char(token->value[0]);
			cmd_index++;
		}
		token = token->next;
	}
	parser->cmd[cmd_index] = NULL;
}