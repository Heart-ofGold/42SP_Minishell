/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:30:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 13:28:59 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_ptr(void **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	ft_free_all(t_token *tokens)
{
	t_token	*aux;

	if (tokens)
	{
		while (tokens->next_token)
		{
			aux = tokens;
			ft_free_array(tokens->cmd);
			free_ptr((void **)&tokens->value);
			free_ptr((void **)&tokens->path);
			tokens = tokens->next_token;
			free_ptr((void **)&aux);
		}
		free_ptr((void **)&tokens->path);
		ft_free_array(tokens->cmd);
		free_ptr((void **)&tokens->value);
		free_ptr((void **)&tokens);
	}
}

void	ft_free_env(t_mini_env	*env_mini)
{
	t_mini_env	*aux;
	
	while (env_mini->next)
	{
		aux = env_mini;
		free_ptr((void **)&env_mini->value);
		free_ptr((void **)&env_mini->name);
		env_mini = env_mini->next;
		free_ptr((void **)&aux);
	}
	free_ptr((void **)&env_mini->value);
	free_ptr((void **)&env_mini->name);
	free_ptr((void **)&env_mini);
}

void	ft_clean_mem(t_token *tokens)
{
	ft_free_all(tokens);
}

/**
*@brief Function for exiting with failure.
*@param none
*@return none.
*/
void	exit_error(t_mini_env *mini_env)
{
	ft_printf("Goodbye, cadet!\n");
	ft_free_env(mini_env);
	rl_clear_history();
	exit(EXIT_FAILURE);
}
