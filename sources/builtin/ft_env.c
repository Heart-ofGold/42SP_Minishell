/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:53 by feralves          #+#    #+#             */
/*   Updated: 2023/04/06 22:44:07 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with no options
void	ft_env(t_token *token, char **envp[])
{
	int	i;

	i = 0;
	token->path = ft_strdup("minishell/path");
	if (token->cmd[1])
	{
		ft_printf("env: does not take more than one argument\n");
	}
	else
	{
		while (envp && *envp && envp[0][i])
		{
			ft_printf ("%s\n", envp[0][i]);
			i++;
		}
	}
}
