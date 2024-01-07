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
t_envp	*create_node(char *envp)
{
	t_envp *tmp;

	tmp = (t_envp *)malloc(sizeof(t_envp));
	if (!tmp)
		return (NULL);
	tmp->data = ft_strdup(envp);
	if (!tmp->data)
		{
			free (tmp);
			return (NULL);
		}
	tmp->next = NULL;	
	return (tmp);
}

t_envp* dup_env(char **envp)
{
	t_envp *data;
	t_envp *resault;
	int		i;

	i = 0;
	data = NULL;
	resault = NULL;
	while (envp[i] != NULL)
	{
		if (data == NULL)
		{
			data = create_node(envp[i]);
			resault = data;
		}
		else
		{
			data->next = create_node(envp[i]);
			data = data->next;
		}
		i++;
	}
	return (resault);
}

// t_envp *add_env_variable(t_envp *data, char *envp)
// {   
// 	t_envp  *newnode;

// 	if (data == NULL)
//         return (create_node(envp));
// 	else {
//     newnode = create_node((envp));
//         newnode->next = data;
//         return newnode;
//     }
// }

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