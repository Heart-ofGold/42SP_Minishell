/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:59:15 by feralves          #+#    #+#             */
/*   Updated: 2023/04/06 22:26:43 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with only an relative or absolute path
void	ft_cd(t_token *token)
{
	token->path = ft_strdup("minishell/path");
	ft_printf("Cd command\n");
}
