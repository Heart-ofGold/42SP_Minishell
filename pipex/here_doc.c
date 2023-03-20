/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:31:04 by feralves          #+#    #+#             */
/*   Updated: 2023/03/19 17:29:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    here_doc(t_data *p_data)
{
    if (argc < 6)
		error_args("Invalid number of arguments\n\
Needed: cmd LIMITER cmd cmd1 output_file", p_data, 1);
	p_data->here_doc = 1;
	p_data->infile = //leitura do terminal
    p_data->outfile = open(
            argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
    )
}