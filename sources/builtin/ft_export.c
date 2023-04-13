/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:00:42 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 16:22:42 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_valid_cmd(t_token *token)
{
	t_token	*aux;

	aux = token;
	while (aux->next_token)
	{
	//	aux->cmd[1];
		aux = aux->next_token;
	}
	return (0);
}

//with no options
void	ft_export(t_token *token, t_mini_env *mini_env)
{
	char	**command;
	t_mini_env	*aux;
	int			i;

	i = 0;
	token->path = ft_strdup("minishell/path");
	if (!token->cmd[1])
		return (ft_env_from_export(token, mini_env));
	aux = mini_env;
//	if (!check_valid_cmd(token->cmd))
//		return ;
	while (token->next_token)
	{
		command = ft_split(token->cmd[i], '=');
		while (aux->next)
		{
			if (!ft_strncmp(command[0], aux->name, ft_strlen(command[1])))
			{
				aux->name = command[0];
				aux->value = command[1];
			}
			i++;
			aux = aux->next;
		}
		aux->name = command[0];
		aux->value = command[1];
	}
}
