/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:41:23 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 20:26:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*find_command(char **possible_paths, char *cmd)
{
	int		i;
	char	*temp;
	char	*command;

	i = 0;
	command = ft_strjoin("/", cmd);
	while (possible_paths[i])
	{
		temp = ft_strjoin(possible_paths[i], command);
		if (access(temp, F_OK) == 0)
		{
			free(command);
			if (access(temp, X_OK) == 0)
				return (temp);
			else
				return (NULL);
		}
		free(temp);
		i++;
	}
	free(command);
	return (NULL);
}

char	*get_path(char *paths, char *parser)
{
	char	**possible_paths;
	char	*right_path;
	char	*cmd;

	cmd = ft_strtrim_mod(ft_strdup(parser), " ");
	if (cmd == NULL)
		return (NULL);
	possible_paths = ft_split(paths, ':');
	right_path = find_command(possible_paths, cmd);
	ft_free_array(possible_paths);
	free(cmd);
	if (right_path == NULL)
		return (NULL);
	return (right_path);
}

char	*find_path(t_mini_env *envp)
{
	t_mini_env	*temp;

	temp = envp;
	while (ft_strncmp(temp->name, "PATH", 4))
		temp = temp->next;
	if (!ft_strncmp(temp->name, "PATH", 4))
		return (temp->value);
	return (NULL);
}
