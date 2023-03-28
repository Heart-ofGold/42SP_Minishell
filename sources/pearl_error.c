/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pearl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:06:17 by feralves          #+#    #+#             */
/*   Updated: 2023/03/27 22:26:01 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_quotes(char *argument)
{
	int		index;
	int		counter;

	counter = 0;
	index = 0;
	while (argument[index])
	{
		if (argument[index] == '\'' || argument[index] == '\"')
			counter++;
		index++;
	}
	if (counter % 2 != 0)
		return (-1);
	return (0);
}

int	check_input(char *input)
{
	int	check;

	check = FALSE;
	if (!input || ft_strlen(input) == 0 || ft_strncmp(input, " ", 1) == 0)
		check = TRUE;
	else if (check_quotes(input))
	{
		check = TRUE;
		if_cmd_error("Error: Unmatched quotes.", EXIT_FAILURE);
	}
	return (check);
}
