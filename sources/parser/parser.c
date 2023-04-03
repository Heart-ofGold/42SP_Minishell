/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/03 16:27:59 by feralves         ###   ########.fr       */
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
	parser->cmd = (char ***)malloc(sizeof(char **) * token->n_tokens + 1);
	if (!parser->cmd)
		return (NULL);
	while (i < token->n_tokens)
	{
		parser->cmd[i] = (char **)malloc(sizeof(char *) * token->n_tokens + 1);
		if (!parser->cmd[i])
			return (NULL);
		i++;
	}
	parser->i = 0;
	parser->n_cmds = 0;
	return (parser);
}

void	parsing(t_token *token)
{
	t_parser	*parser;
	int			index;

	index = 0;
	parser = start_parser(token);
	if (!token->next)
	{
		one_cmd(parser, token);
		return ;
	}
	while (token->next)
	{
		if (token->type == WORD)
		{
			parser->cmd[parser->i][index] = token->value;
			index++;
		}
		else if (token->type == !WORD)
		{
			index = 0;
			parser->n_cmds++;
			parser->i++;
		}
		token = token->next;
	}
	last_cmd(parser, token, parser->i);
	test_parser(parser);
}
	//	ft_printf("\tteste\n");
		// ft_printf("token->type: %d\n", token->type);
		// ft_printf("token->value: %s\n", token->value);
