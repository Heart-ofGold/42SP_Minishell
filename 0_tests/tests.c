/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:39:33 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 20:24:39 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	t_token	*temp;

	temp = tokens;
	while (temp)
	{
		ft_printf("[%d] %s\n", temp->type, temp->value);
		temp = temp->next_cmd;
	}
	temp = tokens;
	while (temp->next_redirection)
	{
		temp = tokens->next_redirection;
		ft_printf("[%d] %s\n", temp->type, temp->value);
	}
}
