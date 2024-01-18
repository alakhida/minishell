/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:52:54 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/18 01:39:36 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "./libft_42/libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_redir {
	DIR_IN,
	DIR_OUT,
	DIR_APPRND,
	DIR_HERDOC,
	NONE
} redir;

typedef struct s_minishell
{
	char				*cmds;
	char				*cmd_path;
	char 				**args;
	bool				has_no_option;
	char 				*outfile;
	char 				*infile;
	char 				*current_dir;
	bool				pipe;
	enum e_redir		in_type;
	enum e_redir		out_type;
	struct s_minishell	*next;
	struct s_minishell	*prev;
}t_minishell;

typedef struct s_envp {
	char *data;
	struct s_envp *next;
} t_envp;

int			echo_opt(const char *av);
void		ft_echo(int argc, t_minishell *av);
void		print_export(t_envp *envp);
void		remove_env_variable(t_envp **data, const char *key);
void		ft_export(t_envp **data, t_minishell *av);
void		add_env_variable(t_envp **data, char *envp);
char		*ft_get_the_Key(char *envp);

// int			ft_strcmp(char *s1, char *s2);
// int			ft_strlen(char *s);
// int			ft_strncmp(const char *s1, const char *s2, size_t n);
// char		*ft_strdup(char *src);
// char		*ft_strchr(const char *s, int c);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_strtok(char *str, char *delim);
// void		ft_putstr(char *s);
t_envp		*dup_env(char **envp);
t_envp		*create_node(char *envp);
// void	*ft_calloc(size_t count, size_t size);

