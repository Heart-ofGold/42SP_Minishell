/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/03/30 19:43:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
*@brief Checks if Minishell wants to exit.
*@param input the input sent after the prompt
*@return none.
*/
void	ft_exit(char *input)
{
	if (input[4] == '\0')
	{
		ft_printf("Exiting...\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_strtrim_mod(input, "exit ");
		if (ft_isdigit_mod(input))
		{
			ft_printf("Exiting...\n");
			exit(ft_atoi_mod(input));
		}
		else
			ft_printf("exit: %s: numeric argument required\n", &input[5]);
	}
}

/**
*@brief Function for exiting with failure.
*@param none
*@return none.
*/
void	exit_error(void)
{
	exit(EXIT_FAILURE);
}
