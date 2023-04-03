/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/04/03 14:56:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
*@brief Testes if input is working.
*@param input the input sent after the prompt
*@return none.
*/
int	testing_input(char *input, char *envp[])
{
	t_token	*tokens;

	tokens = lexer(input);
	print_tokens(tokens);
	parsing(tokens);
	free(tokens);
	executor(input, envp);
	return (0);
}
//	ft_printf("comandos: %d\n", tokens->n_cmds);
//	ft_printf("tokens: %d\n", tokens->n_tokens);

/**
*@brief Loop for the minishell to start.
*@param none
*@return none.
*/
void	mini_loop(char *envp[])
{
	char	*input;

	while (1)
	{
		handle_signal();
		input = readline(PROMPT);
		if (!input)
			exit_error();
		if (input)
			add_history(input);
		if (check_input(input))
			continue ;
		testing_input(input, envp);
		free(input);
	}
}

/**
*@brief Checks if Minishell was started with args.
*@param argc
*@param argv
*@return none.
*/
int	main(int argc, char *argv[], char *envp[])
{
	if (argv && argc > 1)
	{
		ft_printf("Error: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	mini_loop(envp);
	rl_clear_history();
}
