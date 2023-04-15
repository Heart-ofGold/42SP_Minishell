/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/04/15 18:34:59 by feralves         ###   ########.fr       */
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


// Define

# define PROMPT "pearl>$ "
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define TRUE 1
# define FALSE 0
# define QUOTE 4 // uma aspas simples ou dupla
# define WHITESPACE 5 // um espaço em branco
# define CHARS_WHITESPACES " \t\n"
# define TEMP_SPACE 1

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
	char			**cmd; //the command split by spaces and parsed
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

typedef struct s_global
{
	t_token			*head_token;
	t_mini_env		*mini_env;
	int 			exit_status;
	int				last_status;
}	t_global;

// Functions

// Signal

void	handle_signal(void);
void	handle_signal_child(void);

// Lexer

void	lexer(char *input, t_global *g);
t_token	*create_redirect_token(char c, int pos);
t_token	*create_pipe_token(int pos);
t_token	*create_word_token(char *input, int start_pos, int end_pos);
t_token	*n_token(char *value, int type, int size);
t_token	*get_next_token(char *input, int end_pos);
t_token	*append_token(t_global *g, t_token *token, t_token *last_token);
char *	when_word(t_global *g, t_token **tmp, char *input);
char *	when_sep_pipe(t_global *g, t_token **tmp, char *input, int	holder);
char *	when_redirect(t_global *g, t_token **tmp, char *input);
char *	when_quotes(t_global *g, t_token **tmp, char *input);
void 	normalize(t_global *g);
t_token	*parsing(t_token *token, t_global *g);
char	**ft_split_pipex(char *argument, t_global *g);

int 	verify_unexpecte_token(t_token *current_token, t_token *last_token);

// Utils

char	*get_value(char **input);
int		check_input(char *input);
int		is_redirect(char c);
int		is_quote(char c);
int		is_whitespace(char c);
int		is_pipe(char c);
int		is_separator(char c);
int		check_quotes(char *argument);
char	*get_env(t_mini_env *env, char *key);
void	error_handler(t_global *g);
char 	*get_env(t_mini_env *env, char *key);
char 	*get_key(char *word, int a, t_global *g);
char 	*sub_error_n(char *str, char *key, int a, t_global *g);
char 	*is_key(char *key, char *str, int a, t_global *g);
void	ft_change_value(t_mini_env **mini_env, char *cmd);

// Builtin functions

void	ft_env(t_token *token, t_mini_env *envp);
void	ft_env_from_export(t_token *token, t_mini_env *mini_env);
void	ft_echo(t_global *g);
void	ft_cd(t_mini_env *env, t_token *token);
int		ft_pwd(t_global *g);
void	ft_export(t_token *token, t_mini_env *mini_env);
void	ft_unset(t_global *g);
void	ft_exit(t_token *token, t_mini_env *mini_env);

// Env functions

void		start_env(t_mini_env **envp);
t_mini_env	*set_mini_env(char *envp[]);
char		**ft_mini_to_envp(t_mini_env *mini_env);
char		*find_path(t_mini_env *envp);

// Executor

char	*get_path(char *paths, char *parser);
void	executor(t_global *g, t_token *token, t_mini_env *mini_env, char *paths);

// Errors

void	if_cmd_error(char *message);
void	exit_error(t_mini_env *mini_env);
void	error_handler(t_global *g);

// Cleaning

void	ft_clean_mem(t_token *tokens);
void	ft_free_all(t_token *tokens);
void	ft_free_env(t_mini_env	*mini_env);

// Testing functions

void	print_tokens(t_token *tokens);
void	ft_print_test_env(t_mini_env *mini_env);

#endif
