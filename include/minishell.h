/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 23:27:45 by feralves         ###   ########.fr       */
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
# define WORD 0 // uma palavra
# define PIPE 1 // um pipe "|"
# define REDIRECT 2 // um redirecionador "<" ou ">"
# define SEPARATOR 3 // um separador ";"
# define QUOTE 4 // uma aspas simples ou dupla
# define WHITESPACE 5 // um espaço em branco

// structs

/**
 * @brief token structure
 */
typedef struct s_token
{
	int				type;	// the token type, e.g. WORD, PIPE, REDIRECT
	int				n_cmds;	// number of commands
	int				n_tokens; // number of tokens
	char			*value;	// the value of the token, eg "ls", ">", "file.txt"
	int				start_pos;// the starting position of the token in the input
	int				end_pos;// the final position of the token in the input
	struct s_token	*next;	// pointer to the next token in the linked list
}	t_token;

typedef struct s_parser
{
	char	***cmd;
}	t_parser;

// Functions

// Signal

void	handle_signal(void);
void	handle_signal_child(void);

// Lexer

t_token	*lexer(char *input);
t_token	*create_redirect_token(char c, int pos);
t_token	*create_pipe_token(int pos);
t_token	*create_word_token(char *input, int start_pos, int end_pos);
t_token	*get_next_token(char *input, int *pos);
t_token	*new_token(char *value, int type);
void	append_token(t_token **tokens, t_token *token);

// Parser

void	parsing(t_token *token);

// Utils

char	*get_value(char **input);
int		check_input(char *input);
int		is_redirect(char c);
int		is_quote(char c);
int		is_whitespace(char c);
int		is_pipe(char c);
int		is_separator(char c);

// Builtin functions

void	ft_env(char *input);
void	ft_echo(char *input);
void	ft_cd(char *input);
void	ft_pwd(char *input);
void	ft_export(char *input);
void	ft_unset(char *input);
void	ft_exit(char *input);

// Executor

char	*get_path(char *envp[], char *cmd);
void	executor(char *input, char *envp[]);

// Errors

void	if_cmd_error(char *message);
void	exit_error(void);

// Testing functions

void	print_tokens(t_token *tokens);

#endif
