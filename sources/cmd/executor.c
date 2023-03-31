/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/03/31 19:42:48 by feralves         ###   ########.fr       */
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

void	executor_path(char *input, char *envp[])
{
	char	*path;
	pid_t	pid;
	int		status;
	char	**cmd;

	path = get_path(envp, input);
	if (!path)
		ft_printf("%s: command not found\n", input);
	else
	{
		cmd = mini_function(input);
		pid = fork();
		if (pid == -1)
			ft_printf("Error: fork failed\n");
		else if (pid == 0)
			exeggcute(cmd, path, envp);
		else
			wait(&status);
		free(cmd[1]);
		free(cmd[0]);
		free(path);
		free(cmd);
	}
}
/**
{
	char	*path;
	int		check;
	char	**cmd;

	path = get_path(envp, input);
	if (!path)
		ft_printf("%s: command not found\n", input);
	else
	{
		cmd = mini_function(input);
		check = execve(path, cmd, envp);
		ft_printf("Error: execve failed\n");
		exit(check);
	}
}
*/

/**
 * @brief Function that executes the command sent by the user.
 * @param input Command sent by the user.
 * @return void
 */
void	executor(char *input, char *envp[])
{
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
		executor_path(input, envp);
}
