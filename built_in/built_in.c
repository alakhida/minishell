/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:47:10 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/19 05:04:36 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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

void ft_echo(t_minishell *av) 
{
    int newline;
	int		i;

	newline = 0;
	i = 2;
	if (av->args[2] != NULL)
	{
		if (echo_opt(av->args) == 0)
			{
			i+= 1;
			newline = 1;
			}
	while (av->args[i] != NULL)
	{
		ft_putstr(av->args[i]);
			write(1, " ", 1);
		i++;
	}
	
    if (newline == 0)
		write(1,"\n",1);
	}
}