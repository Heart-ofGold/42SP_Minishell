/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/03/30 21:56:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// void	execute_execute(char *input, char **envp, char *path)
// {
// 	int		check;

// 	check = execve(path, &input, envp);
// 	ft_printf("Error: execve failed\n");
// 	ft_printf("Status: %d\n", check);
// }

void	executor_path(char *input, char **envp)
{
	char	*path;
	int		check;

	path = get_path(envp, input);
	if (!path)
		ft_printf("%s: command not found\n", input);
	else
	{
		check = execve(path, &input, envp);
		ft_printf("Error: execve failed\n");
		(void)check;
	}
}
// {
// 	char	*path;
// 	// pid_t	pid;
// 	// int		status;
// 	// int		i;
// 	path = get_path(envp, input);
// 	if (!path)
// 		ft_printf("%s: command not found\n", input);
// 	else
// 	{
// 		execute_execute(input, envp, path);
// 		// pid = fork();
// 		// if (pid == 0)
// 		// else if (pid == -1)
// 		// 	ft_printf("Error: fork failed\n");
// 		// else
// 		// 	wait(&status);
// 		// if (WIFEXITED(status))
// 		// 	i = WEXITSTATUS(status);
// 		// ft_printf("Status: %d\n", i);
// 		// exit (i);
// 	}
// }

/**
 * @brief Function that executes the command sent by the user.
 * @param input Command sent by the user.
 * @return void
 */
void	executor(char *input, char **envp)
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
