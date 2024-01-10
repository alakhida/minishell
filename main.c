#include "minishell.h"


void	ft_env(char **args, t_envp *envp)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	if (ft_strcmp(args[1], "env") == 0)
	{
	while(envp != NULL)
	{
		printf("%s\n", envp->data);
		envp = envp->next;
	}
	}
}
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

t_envp *add_env_variable(t_envp *data, char *envp)
{   
	t_envp  *newnode;

	newnode = (t_envp *)malloc(sizeof(t_envp));
	if (!newnode)
		return (0);
	newnode->data = ft_strdup(envp);
	if (!newnode->data)
		return (0);
	newnode->next = data;
	data = newnode;
	return (data);
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

void	ft_pwd(char **args, t_envp *envp)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	if (ft_strcmp(args[1], "pwd") == 0)
	{
	while(envp != NULL)
	{
		if (ft_strncmp(envp->data, "PWD=", 4) == 0)
		{
			pwd = ft_strdup(envp->data + 4);
			if (!pwd)
				return ;
			break;
		}
		envp = envp->next;
	}
	printf("%s\n", pwd);
	}
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
	key = malloc(sizeof(char) * i + 1);
	i = 0;
	while(envp[i])
	{
		if (envp[i] == '=')
			break;
		key[i] = envp[i];
		i++;
	}
	key[i] = '\0';
	return (key);
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


t_envp	*ft_unset(t_envp *data, t_minishell *av)
{
	t_envp *current;
	t_envp *prev;
	int		i;

	current = data;
	prev = NULL;
	if (av->args[2] == NULL)
		return (data);
	i = ft_strlen(av->args[2]);
	if (ft_strcmp(av->args[1], "unset") == 0)
	{
	if (av->args[2] != NULL)
	{
		while(current != NULL)
		{
			if (ft_strncmp(current->data, av->args[2], i) == 0)
			{
				if (prev == NULL)
				{
					data = current->next;
				}
				else
				{
					prev->next = current->next;
				}
				free (current->data);
				free (current);
				break;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
	}
	}
	return (data);
}

// t_envp *ft_get_exported(t_envp *data)
// {
// 	t_envp *current;
// 	t_envp *newnode;
// 	t_minishell *av;


// 	current = data;
// 	newnode = NULL;
// 	while (current != NULL)
// 	{
// 		if (current->is_exported == 1)
// 		{
			
// 		}
// 		current = current->next;

// 	}
// }

// void	print_export(t_envp *envp)
// {
// 	t_envp *current;

// 	current = envp;
// 	while(current != NULL)
// 	{
// 		if (current->is_exported == 1)
// 		printf("hhhh");
// 			if (current->data != NULL)
// 				printf("declare -x %s\n", current->data);
// 		current = current->next;
// 	}
// }

// t_envp *ft_export(t_envp *data, t_minishell *av)
// {
// 	t_envp *current;
// 	t_envp *prev;
// 	t_envp *tmp;
// 	int		i;

// 	prev = NULL;
// 	if (ft_strcmp(av->args[1], "export") == 0)
// 	{
// 	current = data;
// 	// if (av->args[2] == NULL)
// 	// {
// 	// 	print_export(data);
// 	// 	printf("export\n");
// 	// }
// 	if (av->args[2] != NULL)
// 	{
// 	while (current != NULL)
// 	{
// 	if (current != NULL && ft_strncmp(current-en(av->args[2])) == 0)
// 	{
// 		current->is_exported = 1;
// 		tmp = current->next;
// 		if (prev == NULL)
// 		{
// 				free (current->data);
// 				free (current);
// 				data = tmp;
// 		}
// 		else
// 		{
// 			prev->next = tmp;
// 			free (current->data);
// 			free (current);
// 		}
// 	}
// 	else
// 		prev = current;
// 	}
// 		current = current->next;
// 	}
// 	}
// 	return (data);

// }



t_envp *ft_change_directory(t_envp *data,t_minishell *av)
{
	t_envp *current;
	t_envp *prev;
	char	*pwd;
	char	*oldpwd;
	char	*tmp;

	prev = NULL;
	current = data;
	if (ft_strcmp(av->args[1], "cd") == 0)
	{
		printf("%s\n", getcwd(NULL, 0));
		if (av->args[2] == NULL)
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
		data = add_env_variable(data, tmp);
		//data = remove_env_variable(data, "PWD");
		free(tmp);
		tmp = ft_strjoin("PWD=", pwd);
		if (!tmp)
			return (NULL);
		data = add_env_variable(data, tmp);
		data = remove_env_variable(data, "PWD");
		free(tmp);
		free(oldpwd);
		free(pwd);
	}
	return (data);
}

int main(int ac, char **av, char **enviroment)
{
	t_minishell *arg;
	t_envp	*hold;

	arg = (t_minishell *)malloc(sizeof(t_minishell));
	arg->args = av;
	if (ac > 1)
	{
	hold = dup_env(enviroment);
	ft_pwd(av, hold);
	ft_env(av, hold);
	//printf("Before unset:\n");
	// while (hold != NULL) {
    //     printf("%s\n", hold->data);
    //     hold = hold->next;
    // }

    hold = ft_unset(hold, arg);
	// printf("before cd\n");
	// while (hold != NULL) {
	// 	printf("%s\n", hold->data)
	// 	hold = hold->next;
	// }
	hold = ft_change_directory(hold, arg);
	printf("%s\n", getcwd(NULL, 0));
	printf("after\n");
	// while (hold != NULL) {
	// 	printf("%s\n", hold->data);
	// 	hold = hold->next;
	// }
//	hold = ft_export(hold,arg);
        // printf("After unset:\n");
        // while (hold != NULL) {
        //     printf("%s\n", hold->data);
        //     hold = hold->next;
        // }
	}
}
	
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	// printf("***********************\n");
	//remove_env_variable(hold, "COLORTERM");

	// (void)enviroment;
		//ft_echo(ac, arg);
	// t_minishell *arg;
	// t_envp	*hold2;
	//hold = (t_envp *)malloc(sizeof(t_envp));
	// hold2 = (t_envp *)malloc(sizeof(t_envp));
	// hold2 = dup_env(enviroment);
		// while (hold2 != NULL)
		// {
		// 	printf("%s\n", hold2->data);
		// 	hold2 = hold2->next;
		// }
		// printf("\n\n\n\n\n\n");
		// hold = add_env_variable(hold, "test=zbi");
		// while (hold != NULL)
		// {
		// 	printf("%s\n", hold->data);
		// 	hold = hold->next;
		// }