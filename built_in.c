/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 04:47:10 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/15 04:48:25 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_echo(int argc, t_minishell *av) 
{
    int newline;
	int		i;

	newline = 0;
	i = 2;
	if (ft_strcmp(av->args[1], "echo") == 0)
	{
	if (av->args[2] != NULL)
		if (echo_opt(av->args[2]) == 0)
			{
			i+= 1;
			newline = 1;
			}
	while (i < argc)
	{
		ft_putstr(av->args[i]);
		if (i < argc - 1)
			write(1, " ", 1);
		i++;
	}
    if (newline == 0)
		write(1,"\n",1);
	}
}