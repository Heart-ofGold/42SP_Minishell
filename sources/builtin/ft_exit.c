/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 20:06:30 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_clean_exit(int status)
{
	ft_printf("Exiting...\n");
	rl_clear_history();
	exit(status);
}

void	ft_exit_invalid(char **input, int status, int errorno)
{
	if (errorno == 1)
		ft_printf("exit: exited with too many arguments\n");
	else
		ft_printf("exit: %s: exited with invalid argument\n", input[1]);
	rl_clear_history();
	exit(status);
}

/**
*@brief Checks if Minishell wants to exit.
*@param input the input sent after the prompt
*@return none.
*/
void	ft_exit(t_token *token)
{
	int	i;

	i = 1;
	if (token->cmd[1] == NULL)
		ft_clean_exit(EXIT_SUCCESS);
	else
	{
		while(token->cmd[i])
		{
			if (ft_isdigit_mod(token->cmd[i]))
				ft_clean_exit(ft_atoi_mod(token->cmd[1]));
			else if (token->cmd[2])
				ft_exit_invalid(token->cmd, 42, 1);
			else
				ft_exit_invalid(token->cmd, 2, 0);
			i++;
		}
	}
}

/**
*@brief Function for exiting with failure.
*@param none
*@return none.
*/
void	exit_error(void)
{
	rl_clear_history();
	exit(EXIT_FAILURE);
}
