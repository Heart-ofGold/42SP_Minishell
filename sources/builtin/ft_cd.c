/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/15 19:38:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with only an relative or absolute path
void	ft_cd(t_global *g)
{
	if (g->h_token->cmd[1] == NULL)
	{
		chdir(get_env(g->mini_env, "HOME"));
		return ;
	}
	chdir(g->h_token->cmd[1]);
}
