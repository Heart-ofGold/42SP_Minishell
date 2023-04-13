/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:53 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 16:23:22 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_env_error(t_token *token)
{
	ft_putstr_fd("minishell: env: ‘", 1);
	ft_putstr_fd(token->cmd[1], 1);
	ft_putstr_fd("’: invalid parameter", 1);
	ft_putstr_fd("\n", 1);
}

void	ft_env_from_export(t_token *token, t_mini_env *mini_env)
{
	t_mini_env	*aux;

	aux = mini_env;
	if (token->cmd[1])
		return (ft_env_error(token));
	else
	{
		while (aux->next)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(aux->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(aux->value, 1);
			ft_putstr_fd("\n", 1);
			aux = aux->next;
		}
	}
}

void	ft_env(t_token *token, t_mini_env *mini_env)
{
	t_mini_env	*aux;

	aux = mini_env;
	token->path = ft_strdup("minishell/path");
	if (token->cmd[1])
		return (ft_env_error(token));
	else
	{
		while (aux->next)
		{
			ft_putstr_fd(aux->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(aux->value, 1);
			ft_putstr_fd("\n", 1);
			aux = aux->next;
		}
		ft_putstr_fd(aux->name, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(aux->value, 1);
		ft_putstr_fd("\n", 1);
	}
}
