/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 07:11:42 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/19 05:00:25 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		*ft_cd(t_envp **data)
{
	t_envp	*current;
	char	*pwd;
	current = *data;
	while (current != NULL)
	{
		if (ft_strncmp(current->data, "HOME=", 5) == 0)
		{
			pwd = ft_strdup(current->data + 5);
			if (!pwd)
				return (NULL);
			return (pwd);
		}
		current = current->next;
	}
	return (NULL);
}

t_envp  *ft_change_directory(t_envp **data,t_minishell *av)
{
	t_envp *current;
	char	*pwd;
	char	*oldpwd;
	char	*tmp;

	current = *data;
	if (av->args[2] == NULL)
		pwd = ft_cd(data);
	else
	{
		pwd = ft_strdup(av->args[2]);
		if (!pwd)
			return (NULL);
		oldpwd = getcwd(NULL, 0);
		if (!oldpwd)
			return (NULL);
	}
	if (chdir(pwd) == -1)
	{
		printf("cd: %s: No such file or directory\n", pwd);
		return (NULL);
	}
	tmp = ft_strjoin("OLDPWD=", oldpwd);
	if (!tmp)
		return (NULL);
	add_env_variable(data, tmp);
	remove_env_variable(data, "PWD");
	free(tmp);
	pwd = getcwd(NULL, 0);
	printf("%s\n", pwd);
	tmp = ft_strjoin("PWD=", pwd);
	if (!tmp)
		return (NULL);
	remove_env_variable(data, "PWD");
	add_env_variable(data, tmp);
	free(tmp);
	free(oldpwd);
	free(pwd);
	// printf("%s\n", getcwd(NULL, 0));
	return (current);
}

// t_envp	*ft_change_directory(t_envp **data, t_minishell *av)
// {
// 	int		i;
// 	t_envp	*current;
// 	char	*pwd;
// 	char	*old;

// 	i = 1;
// 	current = *data;
// 	printf("%s\n", getcwd(NULL, 0));
// 	if (av->args[2] == NULL)
// 	{
	
// 		while (current != NULL)
// 		{
// 		if (ft_strncmp(current->data, "HOME=", 5) == 0)
// 		{
// 			chdir(current->data + 5);
// 			break;
// 		}
// 		current = current->next;
// 		}
// 	}
// 	else
// 	{
// 		pwd = ft_strdup(av->args[2]);
// 		if (!pwd)
// 			return (NULL);
// 		old = getcwd(NULL, 0);
// 		if (!old)
// 			return (NULL);
// 		if (chdir(pwd) == -1)
// 		{
// 			printf("cd: %s: No such file or directory\n", pwd);
// 			return (NULL);
// 		}
// 	// rintf("%s\n", getcwd(NULL, 0));	
// 	}
// 		printf("%s\n", old);
// 	return (current);
	
// 	//printf("%s\n cd: HOME not set\n", av->args[1]);
// 	}