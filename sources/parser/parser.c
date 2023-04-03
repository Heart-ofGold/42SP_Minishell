/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 23:53:10 by feralves         ###   ########.fr       */
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
	parser->n_cmds = token->n_cmds;
	return (parser);
}

void	parsing(t_token *token)
{
	t_parser	*parser;
	int			index;

	index = 0;
	parser = start_parser(token);
	while (token->next)
	{
		if (token->type == WORD)
		{
			parser->cmd[parser->i][index] = ft_strdup(token->value);
			if (token->next->type != WORD)
				parser->i++;
			index++;
		}
		else if (token->type == !WORD)
		{
			index = 0;
			parser->cmd[parser->i++][index] = ft_strdup_char(token->value[0]);
		}
		ft_printf("\tteste\n");
		token = token->next;
	}
	parser->cmd[parser->i] = NULL;
}
		// ft_printf("token->type: %d\n", token->type);
		// ft_printf("token->value: %s\n", token->value);
