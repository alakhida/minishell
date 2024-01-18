/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:47:19 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/18 06:57:12 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_unset(t_envp **data, t_minishell *av)
{
	int i;

	i = 0;
	while (av->args[i])
	{
		remove_env_variable(data, av->args[i]);
		i++;
	}
}