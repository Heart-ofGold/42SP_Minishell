/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/15 18:29:54 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with only an relative or absolute path
void	ft_cd(t_mini_env *env, t_token *token)
{
	if (token->cmd[1] == NULL)
	{
		chdir(get_env(env, "HOME"));
		return ;
	}
	chdir(token->cmd[1]);
}
