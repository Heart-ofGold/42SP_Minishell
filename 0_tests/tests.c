/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:39:33 by feralves          #+#    #+#             */
/*   Updated: 2023/04/13 11:23:24 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*temp;
	int		i;

	temp = tokens;
	while (temp)
	{
		i = 0;
		ft_printf("%s = ", temp->value);
		while (temp->cmd[i])
		{
			ft_printf("[%s]", temp->cmd[i]);
			i++;
		}
		ft_printf("\n");
		temp = temp->next_token;
	}
}

void	ft_print_test_env(t_mini_env *env_mini)
	{
	t_mini_env	*temp;

	temp = env_mini;
	while (temp->next)
	{
		ft_printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
}
