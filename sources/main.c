/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 20:04:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
*@brief Testes if input is working.
*@param input the input sent after the prompt
*@return none.
*/
int	testing_input(char *input)
{
	ft_printf("You wrote: %s\n", input);
	return (0);
}

/**
*@brief Loop for the minishell to start.
*@param none
*@return none.
*/
void	mini_loop(void)
{
	char	*input;

	while (1)
	{
		input = readline(PROMPT);
		if (!input)
			exit_error();
		ft_exit(input);
		if (input && *input)
			add_history(input);
		if (check_input(input))
			continue ;
		testing_input(input);
		free(input);
	}
}

/**
*@brief Checks if Minishell was started with args.
*@param argc
*@param argv
*@return none.
*/
int	main(int argc, char *argv[])
{
	if (argv && argc > 1)
	{
		ft_printf("Error: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	mini_loop();
}
