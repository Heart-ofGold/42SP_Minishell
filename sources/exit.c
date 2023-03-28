/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 19:54:33 by feralves         ###   ########.fr       */
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
	if (ft_strncmp(input, "exit", 4) == 0)
	{
		ft_printf("Exiting...\n");
		exit(EXIT_SUCCESS);
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
