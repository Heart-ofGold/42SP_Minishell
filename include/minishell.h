/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:11:08 by feralves          #+#    #+#             */
/*   Updated: 2023/04/02 15:56:47 by mcarecho         ###   ########.fr       */
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

// structs

/**
 * @brief token structure
 */
typedef struct s_token
{
    int type;           // the token type, e.g. WORD, PIPE, REDIRECT
    char *value;        // the value of the token, eg "ls", ">", "file.txt"
    int start_pos;      // the starting position of the token in the input
    int end_pos;        // the final position of the token in the input
    struct s_token *next;  // pointer to the next token in the linked list
} t_token;


enum token_type
{
    WORD = 0,   // uma palavra
    PIPE = 1,   // um pipe "|"
    REDIRECT = 2, // um redirecionador "<" ou ">"
    SEPARATOR = 3 // 
};

// Functions

t_token *lexer(char *input);
t_token *create_redirect_token(char c, int pos);
t_token *create_pipe_token(int pos);
t_token *create_word_token(char *input, int start_pos, int end_pos);
t_token *get_next_token(char *input, int *pos);
t_token *new_token(char *value, int type);
void	append_token(t_token **tokens, t_token *token);
char	*get_path(char *envp[], char *cmd);
void	executor(char *input, char *envp[]);
int		check_input(char *input);
void	handle_signal(void);
void	handle_signal_child(void);
void	if_cmd_error(char *message);
void	exit_error(void);
int     is_redirect(char c);
int     is_quote(char c);
int     is_whitespace(char c);
void	print_tokens(t_token *tokens);
char	*get_value(char **input);
int     is_separator(char c);


// Builtin functions

void	ft_env(char *input);
void	ft_echo(char *input);
void	ft_cd(char *input);
void	ft_pwd(char *input);
void	ft_export(char *input);
void	ft_unset(char *input);
void	ft_exit(char *input);



#endif
