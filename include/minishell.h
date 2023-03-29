/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/03/28 22:06:54 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// Native libraries

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

// Non-native libraries

# include "libft/libft.h"
# include "pipex.h"

// Define

# define PROMPT "pearl>$ "
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define TRUE 1
# define FALSE 0

// Functions

int		check_input(char *input);
void	handle_signal(void);
void	if_cmd_error(char *message);
void	ft_exit(char *input);
void	exit_error(void);

#endif
