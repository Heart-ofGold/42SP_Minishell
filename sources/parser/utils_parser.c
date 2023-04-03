/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:21:49 by feralves          #+#    #+#             */
/*   Updated: 2023/04/03 16:28:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	one_cmd(t_parser *parser, t_token *token)
{
	int	index;

	index = 0;
	parser->cmd[index][0] = token->value;
	ft_printf("cmd %d: %s\n", index, parser->cmd[index][0]);
}

void	last_cmd(t_parser *parser, t_token *token, int index)
{
	int	cmd_index;

	cmd_index = 0;
	while (token)
	{
		parser->cmd[index][cmd_index] = token->value;
		token = token->next;
		cmd_index++;
	}
	index++;
	parser->cmd[index][0] = NULL;
}
