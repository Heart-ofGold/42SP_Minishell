/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:00:42 by feralves          #+#    #+#             */
/*   Updated: 2023/04/06 22:26:36 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with no options
void	ft_export(t_token *token)
{
	token->path = ft_strdup("minishell/path");
	ft_printf("Export command\n");
}
