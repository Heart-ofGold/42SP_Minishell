/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 19:42:38 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_clean_exit(char *status)
{
	ft_printf("Exiting...\n");
	rl_clear_history();
	exit(status);
}

void	ft_exit_invalid(char *status, int errorno)
{
	if (errorno == 1)
		ft_printf("exit: %s: too many arguments\n", input[i]);
	else
		ft_printf("exit: %s: numeric argument required\n", input[1]);
	rl_clear_history();
	exit(status);
}

/**
*@brief Checks if Minishell wants to exit.
*@param input the input sent after the prompt
*@return none.
*/
void	ft_exit(char **input)
{
	int	i;

	i = 1;
	if (input[1] == NULL)
		ft_clean_exit(EXIT_SUCCESS);
	else
	{
		while(input[i])
		{
			ft_printf("input: %c\n", input[i]);
			if (!ft_isdigit_mod(input[i]))
				ft_clean_exit(200);
			else if (input[2])
				ft_printf("exit: %s: too many arguments\n", input[i]);
			else
				ft_printf("exit: %s: numeric argument required\n", input[1]);
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
