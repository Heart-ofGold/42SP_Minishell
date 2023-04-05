/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:30:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 21:36:23 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_all(t_token *tokens)
{
	while (tokens->next_cmd)
	{
		ft_free_array(tokens->cmd);
		free(tokens->cmd);
		free(tokens->value);
		free(tokens->path);
		tokens = tokens->next_cmd;
	}
	free (tokens);
}

void	ft_clean_mem(t_token *tokens)
{
	ft_free_all(tokens);
}
