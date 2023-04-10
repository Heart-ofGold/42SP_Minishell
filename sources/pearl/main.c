/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 20:13:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
*@brief Testes if input is working.
*@param input the input sent after the prompt
*@return none.
*/
int	testing_input(char *input, t_mini_env *envp, char *paths)
{
	t_token		*tokens;

	tokens = lexer(input);
	tokens = parsing(tokens);
	print_tokens(tokens);
	if (tokens->n_cmds != 0)
		executor(tokens, envp, paths);
	ft_clean_mem(tokens);
	return (0);
}

	/**
*@brief Loop for the minishell to start.
*@param none
*@return none.
*/
void	mini_loop(t_mini_env *mini_env)
{
	char	*input;
	char	*path;

	while (1)
	{
		handle_signal();
		input = readline(PROMPT);
		if (!input)
			exit_error(mini_env);
		if (input)
			add_history(input);
		if (check_input(input))
			continue ;
		path = find_path(mini_env);
		testing_input(input, mini_env, path);
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
	t_mini_env	*mini_env;

	if (argv && argc > 1)
	{
		ft_printf("Error: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	mini_env = set_mini_env(envp);
	mini_loop(mini_env);
	ft_free_env(mini_env);
	rl_clear_history();
}
