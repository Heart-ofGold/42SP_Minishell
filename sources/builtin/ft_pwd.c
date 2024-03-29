/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:58:50 by feralves          #+#    #+#             */
/*   Updated: 2023/04/14 21:04:31 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//with only an relative or absolute path
int	ft_pwd(t_global *g)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL || path[0] == '\0')
	{
		perror("getcwd");
		g->exit_status = 1;
		return (-1);
	}
	ft_putendl_fd(path, 1);
	free(path);
	g->exit_status = 0;
	return (0);
}
