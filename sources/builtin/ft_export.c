/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:00:42 by feralves          #+#    #+#             */
/*   Updated: 2023/04/14 20:59:55 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_varname(char c)
{
	return (ft_isalnum(c) || c == '_');
}

int	check_valid_var(char *name)
{
	if (!ft_isalpha(*name))
		return (FALSE);
	while (*name)
	{
		if (!is_varname(*name))
			return (FALSE);
		name++;
	}
	return (TRUE);
}

void	append_env(t_mini_env **mini_env, char *name, char *value)
{
	t_mini_env	**aux;
	t_mini_env	*temp;

	aux = mini_env;
	temp = (*mini_env)->next;
	(*aux)->next = malloc(sizeof(t_mini_env));
	(*aux)->next->name = ft_strdup(name);
	(*aux)->next->value = ft_strdup(value);
	(*aux)->next->next = temp;
}

void	ft_change_value(t_mini_env **mini_env, char *cmd)
{
	(*mini_env)->value = cmd;
}

//with no options
void	ft_export(t_token *token, t_mini_env *mini_env)
{
	char		**command;
	t_mini_env	*aux;
	int			i;

	i = 0;
	token->path = ft_strdup("minishell/path");
	if (!token->cmd[1])
		return (ft_env_from_export(token, mini_env));
	aux = mini_env;
	while (token->cmd[++i])
	{
		command = ft_split(token->cmd[i], '=');
		if (!command[1] || !check_valid_var(command[0]))
			return ;
		while (aux->next->next)
		{
			if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
				return (ft_change_value(&aux, command[1]));
			aux = aux->next;
		}
		if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
			return (ft_change_value(&aux, command[1]));
		append_env(&aux, command[0], command[1]);
	}
}
