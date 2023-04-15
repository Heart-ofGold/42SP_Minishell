/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/04/15 19:38:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exeggcute(char **cmd, char *path, t_mini_env *mini_env)
{
	int		check;
	char	**envp;

	envp = ft_mini_to_envp(mini_env);
	check = execve(path, cmd, envp);
	ft_printf("Error: execve failed\n");
	exit(check);
}

void	executor_path(t_global *g, char *paths)
{
	pid_t	pid;
	int		status;

	g->h_token->path = get_path(paths, g->h_token->cmd[0]);
	if (!g->h_token->path)
		ft_printf("%s: command not found\n", g->h_token->value);
	else
	{
		pid = fork();
		handle_signal_child();
		if (pid == -1)
			ft_printf("Error: fork failed\n");
		else if (pid == 0)
		{
			handle_signal();
			exeggcute(g->h_token->cmd, g->h_token->path, g->mini_env);
		}
		else
			wait(&status);
	}
}

/**
 * @brief Function that executes the command sent by the user.
 * @param input Command sent by the user.
 * @return void
 */
void	executor(t_global *g, char *paths)
{
	char	*input;

	input = g->h_token->cmd[0];
	if (!ft_strncmp(input, "echo", 5))
		ft_echo(g);
	else if (!ft_strncmp(input, "cd", 3))
		ft_cd(g);
	else if (!ft_strncmp(input, "pwd", 4))
		ft_pwd(g);
	else if (!ft_strncmp(input, "export", 7))
		ft_export(g);
	else if (!ft_strncmp(input, "unset", 6))
		ft_unset(g);
	else if (!ft_strncmp(input, "env", 4))
		ft_env(g);
	else if (!ft_strncmp(input, "exit", 5))
		ft_exit(g);
	else
		executor_path(g, paths);
}
