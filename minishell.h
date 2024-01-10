/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:52:54 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/09 19:31:01 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
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
	char **args;
	char *outfile;
	char *infile;
	char *current_dir;
	enum e_redir in_type;
	enum e_redir out_type;
	 struct s_minishell *next;
}t_minishell;

typedef struct s_envp {
	char *data;
	struct s_envp *next;
} t_envp;

int			echo_opt(const char *av);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strtok(char *str, char *delim);
void		ft_putstr(char *s);
t_envp		*dup_env(char **envp);
t_envp		*create_node(char *envp);
t_envp		*remove_env_variable(t_envp *data, const char *key);
void	*ft_calloc(size_t count, size_t size);

