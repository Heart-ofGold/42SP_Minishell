/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:58:50 by feralves          #+#    #+#             */
/*   Updated: 2023/04/06 22:26:34 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with only an relative or absolute path
void	ft_pwd(t_token *token)
{
	token->path = ft_strdup("minishell/path");
	ft_printf("Pwd command\n");
}
