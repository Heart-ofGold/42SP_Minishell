/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:39 by feralves          #+#    #+#             */
/*   Updated: 2023/04/14 22:01:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_change_env(t_mini_env **mini_env)
{
	(*mini_env)->name = (*mini_env)->next->name;
	(*mini_env)->value = (*mini_env)->next->value;
	(*mini_env) = (*mini_env)->next;
}

//with no options
void	ft_unset(t_global *g)
{
	t_mini_env	*aux;
	int			i;

	i = 0;
	aux = g->mini_env;
	g->head_token->path = ft_strdup("minishell/path");
	ft_printf("Unset command\n");
	if (!g->head_token->cmd[1])
		return ;
	while (g->head_token->cmd[++i])
	{
		if (!ft_strncmp(g->head_token->cmd[i], aux->name, ft_strlen(g->head_token->cmd[i])))
			return (ft_change_env(&aux));
		aux = aux->next;
	}
}
