/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/04/10 20:13:50 by feralves         ###   ########.fr       */
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
	WORD,
	PIPE,
	REDIRECT,
	SEPARATOR,
}	t_type_t;

/**
 * @brief token structure
 */
typedef struct s_token
{
	t_type_t		type;	// the token type, e.g. WORD, PIPE, REDIRECT
	int				n_cmds;	// number of commands
	int				n_tokens; // number of tokens
	char			*value; // the value of the token, eg "ls", ">", "file.txt"
	char			**cmd;
	char			*path;
	struct s_token	*next_token;	// pointer to the next token
}	t_token;

/**
 * @brief token structure
 */
typedef struct s_mini_env
{
	char				*name;
	char				*value;
	struct s_mini_env	*next;
}	t_mini_env;

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
t_token	*parsing(t_token *token);
char	**ft_split_pipex(char *argument);

// Utils

char	*get_value(char **input);
int		check_input(char *input);
int		is_redirect(char c);
int		is_quote(char c);
int		is_whitespace(char c);
int		is_pipe(char c);
int		is_separator(char c);

// Builtin functions

void	ft_env(t_token *token, t_mini_env *envp);
void	ft_echo(t_token *token);
void	ft_cd(t_token *token);
void	ft_pwd(t_token *token);
void	ft_export(t_token *token);
void	ft_unset(t_token *token);
void	ft_exit(t_token *token, t_mini_env *mini_env);

// Env functions

t_mini_env	*set_mini_env(char *envp[]);
char		**ft_mini_to_envp(t_mini_env *mini_env);
char		*find_path(t_mini_env *envp);

// Executor

char	*get_path(char *paths, char *parser);
void	executor(t_token *token, t_mini_env *envp, char *paths);

// Errors

void	if_cmd_error(char *message);
void	exit_error(t_mini_env *mini_env);

// Cleaning

void	ft_clean_mem(t_token *tokens);
void	ft_free_all(t_token *tokens);
void	ft_free_env(t_mini_env	*mini_env);

// Testing functions

void	print_tokens(t_token *tokens);
void	ft_print_test_env(t_mini_env *mini_env);

#endif
