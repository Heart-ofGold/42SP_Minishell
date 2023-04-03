/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/04/03 19:45:37 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exeggcute(char **cmd, char *path, char **envp)
{
	int		check;

	check = execve(path, cmd, envp);
	ft_printf("Error: execve failed\n");
	exit(check);
}

char	**mini_function(char	*input)
{
	char	**cmd;

	cmd = (char **)malloc(2 * sizeof(char *));
	if (!input)
		return (NULL);
	cmd[0] = ft_strdup(input);
	cmd[1] = NULL;
	return (cmd);
}

void	free_mini_function(char **cmd, char *path)
{
	free(cmd[1]);
	free(cmd[0]);
	free(path);
	free(cmd);
}

void	executor_path(t_parser *parser, char *envp[])
{
	char	*path;
	pid_t	pid;
	int		status;

	path = get_path(envp, parser->cmd[0][0]);
	if (!path)
		ft_printf("%s: command not found\n", parser->cmd[0][0]);
	else
	{
		pid = fork();
		handle_signal_child();
		if (pid == -1)
			ft_printf("Error: fork failed\n");
		else if (pid == 0)
		{
			handle_signal();
			exeggcute(parser->cmd[0], path, envp);
		}
		else
			wait(&status);
	}
}
//		free_mini_function(parser->cmd[0], path);

/**
 * @brief Function that executes the command sent by the user.
 * @param input Command sent by the user.
 * @return void
 */
void	executor(t_parser *parser, char *envp[])
{
	char	*input;

	input = parser->cmd[0][0];
	if (!ft_strncmp(input, "echo", 4))
		ft_echo(input);
	else if (!ft_strncmp(input, "cd", 2))
		ft_cd(input);
	else if (!ft_strncmp(input, "pwd", 3))
		ft_pwd(input);
	else if (!ft_strncmp(input, "export", 6))
		ft_export(input);
	else if (!ft_strncmp(input, "unset", 5))
		ft_unset(input);
	else if (!ft_strncmp(input, "env", 3))
		ft_env(input);
	else if (!ft_strncmp(input, "exit", 4))
		ft_exit(input);
	else
		executor_path(parser, envp);
}
