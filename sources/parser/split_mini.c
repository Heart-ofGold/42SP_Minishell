/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 22:24:46 by mcarecho          #+#    #+#             */
/*   Updated: 2023/04/13 11:38:50 by mcarecho         ###   ########.fr       */
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

static void	ft_reswitch(char **cmd, t_global *g)
{
	char	*temp;
	int		pos;
	int		i;

	pos = 0;
	while (cmd[pos])
	{
		ft_expander(cmd[pos], TEMP_SPACE, ' ');
		if (ft_strchr(cmd[pos], '$') && cmd[pos][0] != '\'')
		{
			i = 0;
			while (ft_strchr(&cmd[pos][i], '$') && cmd[pos][i] != '\0' )
			{
				temp = get_key(cmd[pos], i, g);
				cmd[pos] = temp;
				i++;
			}
		}
		pos++;
	}
}

char	**ft_split_pipex(char *argument, t_global *g)
{
	char	**cmd;

	if (check_quotes(argument))
		return (NULL);
	ft_expander(argument, ' ', TEMP_SPACE);
	cmd = ft_split(argument, ' ');
	ft_reswitch(cmd, g);
	return (cmd);
}
