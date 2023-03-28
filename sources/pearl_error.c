/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pearl_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:06:17 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 21:00:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/**
*@brief Checks the string for quotes
*@param argument the string to be checked
*@return -1 if not closed, 0 if closed.
*/
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

/**
*@brief Checks input is empty
*@param input the input sent after the prompt
*@return -1 if only spaces, 0 if others.
*/
int	is_empty(char *input)
{
	int	index;
	int	space;

	index = 0;
	space = 0;
	while (input[index] != '\0')
	{
		if (input[index] == ' ' || input[index] == '\t')
			space++;
		index++;
	}
	if (space == index)
		return (-1);
	return (0);
}

/**
*@brief Checks input (for errors)
*@param input the input sent after the prompt
*@return False if no errors, True if errors.
*/
int	check_input(char *input)
{
	int	check;

	check = FALSE;
	if (!input || ft_strlen(input) == 0)
		check = TRUE;
	else if (is_empty(input))
		check = TRUE;
	else if (check_quotes(input))
		check = TRUE;
	return (check);
}
