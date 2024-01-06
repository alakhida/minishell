/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:59:18 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/06 01:52:52 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"


// int exection_unit(t_minishell *cmd, t_envp) {
	
// 	int tmp_fd;
// 	int pipe_fd[2];
	

// 	while (cmd) {
		
// 	}
	
// }
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int		echo_opt(char **av)
{
	int		i;

	i	= 1;
	if (av[2][0] == '-')
	{
		while (av[2][i])
		{
			if (av[2][i] != 'n')
				return (1);
			else
				i++;
		}
	}
	return (0);
}

void ft_echo(int argc, char **argv) {
    bool newline;
	t_minishell *av;
	int		i;

	newline = false;
	i = 1;
	av->args = argv;
	if (ft_strcmp(av->args[1], "echo") == 0)
	{
		if (ft_strcmp(av->args[2], NULL) == 0)
			return ;
		if (echo_opt(av->args) == 0)
		{
			newline = true;
			argc--;
			av->args++;
		}
		else
		
			argc--;
			i = 1;
			av->args++;
		}
	while (i < argc)
	{
		ft_putstr(av->args[i]);
		if (i < argc - 1)
			write(1, " ", 1);
		i++;
	}
    if (!newline)
		write(1,"\n",1);
	}
}


int main(int ac, char **av)
{
	t_minishell *p;

	//p = calloc(1, sizeof(t_minishell));
	// p[0].args = ft_split("echo -n hello");
	
	//p->args = av;
	//exec(p);
	if (ac > 1)
	{
	p = (t_minishell *)malloc(sizeof(t_minishell));
		if (p)
		{
			p->args = av;
			ft_echo(ac, p->args);
		}
	}
	
}