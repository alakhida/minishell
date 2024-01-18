/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:11:42 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/18 08:23:32 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envp  *ft_change_directory(t_envp *data,t_minishell *av)
{
	t_envp *current;
	t_envp *prev;
	char	*pwd;
	char	*oldpwd;
	char	*tmp;
	int		i;

	i = 0;
	prev = NULL;
	current = data;
	if (av->args[i + 1] == NULL)
	{
		while (current != NULL)
		{
			if (ft_strncmp(current->data, "HOME=", 5) == 0)
			{
				pwd = ft_strdup(current->data + 5);
				if (!pwd)
					return (NULL);
				break;
			}
			current = current->next;
		}
	}
	else
	{
		pwd = ft_strdup(av->args[2]);
		if (!pwd)
			return (NULL);
	}
	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
			return (NULL);
	if (chdir(pwd) == -1)
	{
		printf("cd: %s: No such file or directory\n", pwd);
		return (NULL);
	}
	tmp = ft_strjoin("OLDPWD=", oldpwd);
	if (!tmp)
		return (NULL);
	add_env_variable(&data, tmp);
		//data = remove_env_variable(data, "PWD");
	free(tmp);
	pwd = getcwd(NULL, 0);
	tmp = ft_strjoin("PWD=", pwd);
	if (!tmp)
		return (NULL);
	remove_env_variable(&data, "PWD");
	add_env_variable(&data, tmp);
	free(tmp);
	free(oldpwd);
	free(pwd);
	}
	// printf("%s\n", getcwd(NULL, 0));
	return (data);
}