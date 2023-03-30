/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:23:13 by feralves          #+#    #+#             */
/*   Updated: 2023/03/30 19:45:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	executor_path(char *input, char **envp)
{
	if (!get_path(envp, input))
		ft_printf("%s: command not found\n", input);
	else
	{
		ft_printf("Path: %s\n", get_path(envp, input));
	}
}

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
