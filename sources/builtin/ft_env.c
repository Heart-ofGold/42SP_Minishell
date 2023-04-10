/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:37:53 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 19:19:51 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with no options
void	ft_env(t_token *token, t_mini_env *mini_env)
{
	t_mini_env	*aux;

	aux = mini_env;
	token->path = ft_strdup("minishell/path");
	if (token->cmd[1])
	{
		ft_printf("env: does not take more than one argument\n");
	}
	else
	{
		while (aux->next)
		{
			ft_printf ("%s=%s\n", aux->name, aux->value);
			aux = aux->next;
		}
		ft_printf ("%s=%s\n", aux->name, aux->value);
	}
}
