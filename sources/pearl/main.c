/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:10:34 by feralves          #+#    #+#             */
/*   Updated: 2023/04/14 21:03:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
*@brief Testes if input is working.
*@param input the input sent after the prompt
*@return none.
*/
int	testing_input(char *input, t_global *g, char *paths)
{
	lexer(input, g);
	if (g->exit_status != 0)
		return (g->exit_status);
	g->head_token = parsing(g->head_token, g);
	if (g->head_token->n_cmds != 0)
		executor(g, g->head_token, g->mini_env, paths);
	ft_clean_mem(g->head_token);
	return (0);
}
//	print_tokens(g->head_token);

/**
*@brief Loop for the minishell to start.
*@param none
*@return none.
*/
void	mini_loop(t_global *g)
{
	char	*input;
	char	*path;

	g->exit_status = 0;
	while (1)
	{
		handle_signal();
		g->last_status = g->exit_status;
		g->exit_status = 0;
		input = readline(PROMPT);
		if (!input)
			exit_error(g->mini_env);
		if (input)
			add_history(input);
		if (check_input(input))
			continue ;
		path = find_path(g->mini_env);
		testing_input(input, g, path);
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
	t_global	g;

	if (argv && argc > 1)
	{
		ft_printf("Error: Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	g.mini_env = set_mini_env(envp);
	ft_printf("Welcome to Minishell!\n");
	mini_loop(&g);
	ft_free_env(g.mini_env);
	rl_clear_history();
}
