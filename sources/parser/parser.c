/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:31:27 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 14:01:11 by mcarecho         ###   ########.fr       */
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

// t_parser	*start_parser(t_token *token)
// {
// 	int			i;
// 	t_parser	*parser;

// 	i = 0;
// 	parser = (t_parser *)malloc(sizeof(t_parser));
// 	if (!parser)
// 		return (NULL);
// 	parser->cmd = (char ***)malloc(sizeof(char **) * token->n_cmds + 1);
// 	if (!parser->cmd)
// 		return (NULL);
// 	while (i < token->n_cmds)
// 	{
// 		parser->cmd[i] = (char **)malloc(sizeof(char *) * token->n_cmds + 1);
// 		if (!parser->cmd[i])
// 			return (NULL);
// 		i++;
// 	}
// 	parser->i = 0;
// 	parser->n_cmds = 0;
// 	return (parser);
// }

t_token	*parsing(t_token *token)
{
	t_token		*temp;
	t_type_t	last_type;
	int			index;

	index = 0;
	temp = token;
	last_type = SEPARATOR;
	while (index < token->n_cmds)
	{
		if (temp->type == WORD && last_type != REDIRECT)
		{
			temp->cmd = ft_split_pipex(temp->value);
			index++;
		}
		last_type = temp->type;
		temp = temp->next_token;
	}
	free(temp);
	return (token);
}
