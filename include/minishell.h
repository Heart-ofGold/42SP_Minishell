/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/04/05 19:05:47 by feralves         ###   ########.fr       */
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
# define QUOTE 4 // uma aspas simples ou dupla
# define WHITESPACE 5 // um espaço em branco



// structs

typedef enum e_type_token
{
	WORD , // uma palavra
	PIPE , // um pipe "|"
	REDIRECT , // um redirecionador "<" ou ">"
	SEPARATOR , // um separador ";"
}	t_type_t;

/**
 * @brief token structure
 */
typedef struct s_token
{
	t_type_t		type;	// the token type, e.g. WORD, PIPE, REDIRECT
	int				n_cmds;	// number of commands
	int				n_redirection; // number of redirection
	char			*value; // the value of the token, eg "ls", ">", "file.txt"
	char			**cmd;
	char			*path;
	struct s_token	*next_cmd;	// pointer to the next token of |
	struct s_token	*next_redirection;	// pointer to the next token of type redirection
}	t_token;

// Functions

// Signal

void	handle_signal(void);
void	handle_signal_child(void);

// Lexer

t_token	*lexer(char *input);
t_token	*create_redirect_token(char c, int pos);
t_token	*create_pipe_token(int pos);
t_token	*create_word_token(char *input, int start_pos, int end_pos);
t_token	*n_token(char *value, int type, int size);
t_token	*get_next_token(char *input, int end_pos);
t_token *append_token(t_token *tokens, t_token *token, t_token *last_token);
char *	when_word(t_token *tokens, t_token **tmp, char *input);
char *	when_sep_pipe(t_token *tokens, t_token **tmp, char *input, int	holder);
char *	when_redirect(t_token *tokens, t_token **tmp, char *input);
char *	when_quotes(t_token	*tokens, t_token **tmp, char *input);
t_token *normalize(t_token *token);

// Parser

t_token		*parsing(t_token *token);
// t_parser	*one_cmd(t_token *token);
// void		last_node(t_parser *parser, t_token *token, int index, int j);
char		**ft_split_pipex(char *argument);

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
void	ft_exit(char **input);

// Executor

char	*get_path(char *envp[], char *cmd);
void	executor(t_token *token, char *envp[]);

// Errors

void	if_cmd_error(char *message);
void	exit_error(void);

// Testing functions

void	print_tokens(t_token *tokens);
void	test_parser(t_token *token);

#endif
