/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:54:09 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 16:54:20 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	start_env(t_mini_env **envp)
{
	*envp = malloc(sizeof(t_mini_env));
	(*envp)->name = NULL;
	(*envp)->value = NULL;
	(*envp)->next = NULL;
}

t_mini_env	*set_env_mini(char *envp[])
{
	t_mini_env	*env_mini;
	t_mini_env	*first;
	char		**temp;

	start_env(&first);
	env_mini =  first;
	while (*envp)
	{
		temp = ft_split(*envp, '=');
		env_mini->name = ft_strdup(temp[0]);
		env_mini->value = ft_strdup(temp[1]);
		envp++;
		ft_free_array(temp);
		if (*envp)
		{
			start_env(&env_mini->next);
			env_mini = env_mini->next;
		}
	}
	env_mini->next = NULL;
	return(first);
}
