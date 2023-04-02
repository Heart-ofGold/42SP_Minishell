/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:39:33 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 17:39:44 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tokens(t_token *tokens)
{
	while (tokens)
	{
		ft_printf("[%d] %s.\n", tokens->type, tokens->value);
		tokens = tokens->next;
	}
}
