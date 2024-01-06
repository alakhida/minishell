#include "minishell.h"

// int		search_for(char *envp)
// {
// 	int		i = 0;
// 	while(envp[i])
// 	{
// 		if (envp[i] == '=')
// 			break;
// 		i++;
// 	}
// 	return (i);
// }

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_envp	*create_node(char *envp) {
	t_envp *tmp;
	int		len;

	len	=	ft_strlen(envp);
	tmp = (t_envp *)malloc(sizeof(t_envp));
	tmp->data = malloc(sizeof(t_envp));
	tmp->data = envp;
	tmp->next = NULL;	
	return (tmp);
}

char *ft_get_the_Key(char *envp)
{
	int		i = 0;
	char	*key;

	while(envp[i])
	{
		if (envp[i] == '=')
			break;
		i++;
	}
	key = malloc(sizeof(char) * i);
	i = 0;
	while(envp[i])
	{
		if (envp[i] == '=')
			break;
		key[i] = envp[i];
		i++;
	}
	return (key);
}

char *ft_get_the_Value (char *envp)
{
	int		i = 0;
	int		j = 0;
	char	*value;

	if (envp == NULL)
		return (NULL);
	if (!strchr(envp, '='))
		return (NULL);
	while(envp[i])
	{
		if (envp[i] == '=')
			break;
		i++;
	}
	value = malloc(sizeof(char) * (ft_strlen(envp) - i));
	i++;
	while(envp[i])
	{
		value[j] = envp[i];
		i++;
		j++;
	}
	return (value);
}

t_envp* dupenvp(char **envp)
{
	t_envp *data;\
	t_envp *tmp;
	int		i;

	i = 0;
	data = NULL;
	tmp = NULL;
	while (envp[i] != NULL)
	{
		if (data == NULL)
		{
			data = create_node(envp[i]);
			tmp = data;
		}
		else
		{
			data->next = create_node(envp[i]);
			data = data->next;
		}
		i++;
	}
	return (tmp);
}

t_envp *add_env_variable(t_envp *data, char *envp)
{   
	t_envp  *newnode;

	if (data == NULL)
        return (create_node(envp));
	else {
    newnode = create_node((envp));
        newnode->next = data;
        return newnode;
    }
}

t_envp *remove_env_variable(t_envp *data, const char *key) {
    t_envp *prev;
    t_envp *current;
    t_envp *ndata;
	t_envp *nextnode;
	
	ndata = data;
	current = data;
	prev = NULL;
    while (current != NULL) {
        if (strcmp(key, ft_get_the_Key(current->data)) == 0) 
		{
            nextnode = current->next;
            if (prev == NULL)
			{
                free(current);
                return(nextnode);
            }
			else
			{
                prev->next = nextnode;
                free(current);
                return (ndata);
            }
        } 
		else
		{
            prev = current;
            current = current->next;
        }
    }
    return ndata;
}

int change_directory(t_minishell *data, char *path)
{
	if (chdir(path) != 0)
	{
		printf("minishell: cd: %s: %s\n", path, strerror(errno));
		return (1);
	}
	free(data->current_dir);
	data->current_dir = path;
	return (0);
}

int main (int ac, char ** av , char **envp)
{
	t_envp *data;
	t_envp *data2;
	static char *path;

	path = (char *)NULL;
	while (1)
	{
		path = readline("minishell$: ");
		if (strcmp(av[1], "cd") == 0)
		{
			change_directory(data, av[1]);
		}
		else
		{
			printf("minishell: %s: command not found\n", av[1]);
		}
	}
		// else if (strcmp(av[1], "pwd") == 0)
		// {
		// 	printf("%s\n", data->current_dir);
		// }
		// else if (strcmp(av[1], "env") == 0)
		// {
		// 	data2 = data;
		// 	while (data2 != NULL)
		// 	{
		// 		printf("%s\n", data2->data);
		// 		data2 = data2->next;
		// 	}
		// }
		// else if (strcmp(av[1], "export") == 0)
		// {
		// 	scanf("%s", av[1]);
		// 	data = add_env_variable(data, av[1]);
		// }
		// else if (strcmp(av[1], "unset") == 0)
		// {
		// 	scanf("%s", av[1]);
		// 	data = remove_env_variable(data, av[1]);
		// }
		// else if (strcmp(av[1], "exit") == 0)
		// {
		// 	return (0);
		// }
	// data = dupenvp(envp);
	// data2 = remove_env_variable(data, "COMMAND_MODE");
	// while (data2 != NULL)
	// {
	// 	printf("%s\n", data2->data);
	// 	data2 = data2->next;
	// }
}
