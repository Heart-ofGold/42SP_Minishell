/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:54:09 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 17:21:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

size_t	minienv_size(t_mini_env *mini_env)
{
	size_t		size;
	t_mini_env	*aux;

	size = 0;
	aux = mini_env;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}

char	*append_mini_env(char *first, char *last)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(first, "=");
	result = ft_strjoin(temp, last);
	free(temp);
	return (result);
}

char	**ft_mini_to_envp(t_mini_env *mini_env)
{
	t_mini_env	*temp;
	char		**envp;
	int			i;

	temp = mini_env;
	i = 0;
	envp = malloc(sizeof(char *) * (minienv_size(mini_env) + 1));
	if (!envp)
		return (NULL);
	while (temp->next)
	{
		envp[i] = append_mini_env(temp->name, temp->value);
		i++;
		temp = temp->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	start_env(t_mini_env **envp)
{
	*envp = malloc(sizeof(t_mini_env));
	(*envp)->name = NULL;
	(*envp)->value = NULL;
	(*envp)->next = NULL;
}

t_mini_env	*set_mini_env(char *envp[])
{
	t_mini_env	*mini_env;
	t_mini_env	*first;
	char		**temp;
	int			i;

	i = 0;
	start_env(&first);
	mini_env = first;
	while (envp[i])
	{
		temp = ft_split(envp[i++], '=');
		mini_env->name = ft_strdup(temp[0]);
		if (temp[1])
			mini_env->value = ft_strdup(temp[1]);
		else
			mini_env->value = ft_strdup("");
		ft_free_array(temp);
		if (envp[i])
		{
			start_env(&mini_env->next);
			mini_env = mini_env->next;
		}
	}
	mini_env->next = NULL;
	return (first);
}
