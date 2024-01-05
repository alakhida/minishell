/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:52:54 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/04 23:04:14 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum e_redir {
	DIR_IN,
	DIR_OUT,
	DIR_APPRND,
	DIR_HERDOC,
	NONE
} redir;

typedef struct s_minishell
{
	char **args;
	char *outfile;
	char *infile;
	enum e_redir in_type;
	enum e_redir out_type;
	 struct t_minishell *next;
}t_minishell;

typedef struct s_envp {
	char *data;
	struct t_envp *next;
} t_envp;

