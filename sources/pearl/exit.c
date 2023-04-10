/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:30:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 14:25:52 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_all(t_token *tokens)
{
	t_token	*aux;

	if (tokens)
	{
		while (tokens->next_token)
		{
			aux = tokens;
			ft_free_array(tokens->cmd);
			free(tokens->value);
			free(tokens->path);
			tokens = tokens->next_token;
			free(aux);
		}
		free(tokens->path);
		ft_free_array(tokens->cmd);
		free(tokens->value);
		free(tokens);
	}
}

void	ft_clean_mem(t_token *tokens)
{
	ft_free_all(tokens);
}
