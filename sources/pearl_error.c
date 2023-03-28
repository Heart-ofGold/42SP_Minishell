/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pearl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:06:17 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 17:22:11 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_quotes(char *argument)
{
	int		index;
	int		counter_1;
	int		counter_2;

	counter_1 = 0;
	counter_2 = 0;
	index = 0;
	while (argument[index])
	{
		if (argument[index] == '\'')
			counter_1++;
		else if (argument[index] == '\"')
			counter_2++;
		index++;
	}
	if (counter_1 % 2 != 0 || counter_2 % 2 != 0)
	{
		ft_putendl_fd("Error: Unmatched quotes.", 2);
		return (-1);
	}
	return (0);
}

int	check_input(char *input)
{
	int	check;

	check = FALSE;
	if (!input || ft_strlen(input) == 0 || ft_strncmp(input, " ", 1) == 0)
		check = TRUE;
	else if (check_quotes(input))
		check = TRUE;

	return (check);
}
