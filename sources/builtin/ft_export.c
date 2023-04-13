/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:00:42 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 17:48:41 by feralves         ###   ########.fr       */
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

	aux = mini_env;
	ft_printf("\tappend test\n");
	// while ((*mini_env)->next)
	// 	(*mini_env) = (*mini_env)->next;
	(*aux)->next = malloc(sizeof(t_mini_env));
	(*aux)->next->name = ft_strdup(name);
	(*aux)->next->value = ft_strdup(value);
	(*aux)->next->next = NULL;
}

//with no options
void	ft_export(t_token *token, t_mini_env *mini_env)
{
	char	**command;
	t_mini_env	*aux;
	int			i;

	i = 1;
	token->path = ft_strdup("minishell/path");
	if (!token->cmd[1])
		return (ft_env_from_export(token, mini_env));
	aux = mini_env;
	while (token->cmd[i])
	{
		command = ft_split(token->cmd[i], '=');
		if (!check_valid_var(token->cmd[0]))
			return ;
		while (aux->next)
		{
			if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
			{
				aux->value = command[1];
				return ;
			}
			aux = aux->next;
		}
		if (!ft_strncmp(command[0], aux->name, ft_strlen(command[0])))
			{
				aux->value = command[1];
				return ;
			}
		ft_printf("\texport test %d: %s\n", i, command[0]);
		i++;
		append_env(&aux, command[0], command[1]);
	}
}
