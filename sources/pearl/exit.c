/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:30:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 19:49:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_all(t_token *tokens)
{
	t_token	*aux;

	if (tokens)
	{
		while (tokens->next_token)
		{
			aux = tokens;
			ft_free_array(tokens->cmd);
			free(tokens->value);
			free(tokens->path);
			tokens = tokens->next_token;
			free(aux);
		}
		free(tokens->path);
		ft_free_array(tokens->cmd);
		free(tokens->value);
		free(tokens);
	}
}

void	ft_free_env(t_mini_env	*env_mini)
{
	while (env_mini->next)
	{
		free(env_mini->value);
		free(env_mini->name);
		free(env_mini);
		env_mini = env_mini->next;
	}
	free(env_mini->value);
	free(env_mini->name);
	free(env_mini);
}

void	ft_clean_mem(t_token *tokens)
{
	ft_free_all(tokens);
}
