/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:30:33 by feralves          #+#    #+#             */
/*   Updated: 2023/04/15 18:39:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with -n
void	ft_echo(t_global *g)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = TRUE;
	g->head_token->path = ft_strdup("minishell/path");
	if (g->head_token->cmd[i])
	{
		if (!ft_strncmp(g->head_token->cmd[i], "-n", 3))
		{
			new_line = FALSE;
			i++;
		}
		while (g->head_token->cmd[i])
		{
			ft_putstr_fd (g->head_token->cmd[i], 1);
			i++;
			if (g->head_token->cmd[i])
				ft_putstr_fd (" ", 1);
		}
	}
	if (new_line)
		ft_putstr_fd("\n", 1);
	g->exit_status = 0;
}
