/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:30:59 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 16:54:05 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*@brief checks for a digit (0 through 9).
*@param c Character as a void
*@return returns non-zero value if c is a digit, else it returns 0
*/
int	ft_isdigit_mod(void *c)
{
	int	*i;

	i = (int *)c;
	if (!ft_isdigit(*i))
		return (2);
	return (0);
}
