/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:08:08 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/18 03:56:00 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	key_cmp(const char *s1, const char *s2)
{
	puts("1");
	int i = 0;
	if (!s1 || !s2)
		return 1;
	puts("2");
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return 1;
		i++;
	}
	puts("3");
	if (!s2[i] && s1[i] && s1[i] != '=')
		return 1;
	puts("4");
	return 0;
};

void remove_env_variable(t_envp **data, const char *key) {
    t_envp *current;
	t_envp *prev;

	current = *data;
	prev = NULL;
	while (current != NULL)
	{
		if (key_cmp(current->data, key) == 0)
		{
			if (current == *data)
			{
				*data = current->next;
				free(current->data);
				current->data = NULL;
				free(current);
				current = NULL;
			}
			else if (current->next == NULL)
			{
				free(current->data);
				free(current);
				prev->next = NULL;
			}
			else
			{
				prev->next = current->next;
				free(current->data);
				free(current);
			}
			return;
		}
		prev = current;
		current = current->next;
	}
}
void	add_env_variable(t_envp **data, char *envp)
{   
	t_envp  *newnode;
	t_envp  *current;

	current = *data;
	newnode = (t_envp *)malloc(sizeof(t_envp));
	if (!newnode)
		return ;
	newnode->data = ft_strdup(envp);
	if (!newnode->data)
		return ;
	newnode->next = *data;
	while (current->next != NULL)
		current = current->next;
	current->next = newnode;
	newnode->next = NULL;
	// free (newnode);
}

void	print_export(t_envp *envp)
{
	t_envp *current;

	current = envp;
	while(current != NULL)
	{
			if (current->data != NULL)
				printf("declare -x %s\n", current->data);
		current = current->next;
	}
}

bool	already_exist(t_envp **data, char *key)
{
	t_envp *current;

	current = *data;
	while (current != NULL && key != NULL)
	{
		if (ft_strncmp(current->data, key, ft_strlen(key)) == 0)
		{
			free(key);
			return (true);
		}
		current = current->next;
	}
	if (key != NULL)
		free(key);
	return (false);
}

void	ft_export(t_envp **data, t_minishell *av)
{
	t_envp *current;
	int		i;
	char	*tmp;

	current = *data;
	i = 0;
	// printf("%s\n", av->args[0]);
	if (av->args[i] == NULL)
	{
		print_export(*data);
		return;
	}
	else
	{
		tmp = ft_get_the_Key(av->args[0]);
		i = ft_strlen(tmp);
		if (ft_strchr(av->args[0], '=') == NULL)
			return;
		else
		if (already_exist(data, ft_get_the_Key(av->args[0])) == true)
		{
			// printf("%s\n", tmp);
			remove_env_variable(data, tmp);
			add_env_variable(data, av->args[0]);
		}
		else
		{
			// puts("here");
			add_env_variable(data, av->args[0]);
		}
	}
}