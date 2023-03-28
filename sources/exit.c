/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:40:47 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 19:54:33 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_exit(char *input)
{
	if (ft_strncmp(input, "exit", 4) == 0)
	{
		ft_printf("Exiting...\n");
		exit(EXIT_SUCCESS);
	}
}

void	exit_error(void)
{
	exit(EXIT_FAILURE);
}
