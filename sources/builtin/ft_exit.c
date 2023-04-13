/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 13:23:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_clean_exit(t_token *token, int status)
{
	ft_printf("Goodbye, cadet!\n");
	ft_clean_mem(token);
	rl_clear_history();
	exit(status);
}

void	ft_exit_invalid(t_token *token, char **input, int status, int errorno)
{
	if (errorno == 1)
		ft_printf("exit: exited with too many arguments\n");
	else
		ft_printf("exit: %s: exited with invalid argument\n", input[1]);
	ft_clean_mem(token);
	rl_clear_history();
	exit(status);
}

/**
*@brief Checks if Minishell wants to exit.
*@param input the input sent after the prompt
*@return none.
*/
void	ft_exit(t_token *token, t_mini_env *mini_env)
{
	int	i;

	i = 1;
	token->path = ft_strdup("minishell/path");
	ft_free_env(mini_env);
	if (token->cmd[1] == NULL)
		ft_clean_exit(token, EXIT_SUCCESS);
	else
	{
		while (token->cmd[i])
		{
			if (ft_isdigit_mod(token->cmd[i]))
				ft_clean_exit(token, ft_atoi_mod(token->cmd[1]));
			else if (token->cmd[2])
				ft_exit_invalid(token, token->cmd, 42, 1);
			else
				ft_exit_invalid(token, token->cmd, 2, 0);
			i++;
		}
	}
}
