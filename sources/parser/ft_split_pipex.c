/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:24:46 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/04 22:30:09 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	ft_expander(char *argument, char previous, char after)
{
	int		index;
	char	value;

	index = 0;
	value = 0;
	while (argument[index])
	{
		if (argument[index] == '\'' || argument[index] == '\"')
		{
			value = argument[index];
			index++;
			while (argument[index] != value)
			{
				if (argument[index] == previous)
					argument[index] = after;
				index++;
			}
		}
		index++;
	}
	return (value);
}

static void	ft_reswitch(char **cmd)
{
	int		pos;
	char	*temp;

	pos = 0;
	while (cmd[pos])
	{
		ft_expander(cmd[pos], TEMP_SPACE, ' ');
		temp = ft_strtrim(cmd[pos], "\'\"");
		free(cmd[pos]);
		cmd[pos] = temp;
		pos++;
	}
}

static int	check_quotes(char *argument)
{
	int		index;
	int		counter;

	counter = 0;
	index = 0;
	while (argument[index])
	{
		if (argument[index] == '\'' || argument[index] == '\"')
			counter++;
		index++;
	}
	if (counter % 2 != 0)
		return (-1);
	return (0);
}

char	**ft_split_pipex(char *argument)
{
	char	**cmd;

	if (check_quotes(argument))
		return (NULL);
	ft_expander(argument, ' ', TEMP_SPACE);
	cmd = ft_split(argument, ' ');
	ft_reswitch(cmd);
	return (cmd);
}
