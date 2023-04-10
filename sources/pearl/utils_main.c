/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:37:47 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 19:38:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*find_path(t_mini_env *envp)
{
	t_mini_env	*temp;
	int	i = 0;

	temp = envp;
	while (ft_strncmp(temp->name, "PATH", 4))
		temp = temp->next;
	if (!ft_strncmp(temp->name, "PATH", 4))
		return (temp->value);
	ft_printf ("%d, does this work?\n", i++);
	return (NULL);
}
