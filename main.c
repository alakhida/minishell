#include "minishell.h"


void	ft_env(t_envp *envp)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = NULL;
	while(envp != NULL)
	{
		printf("%s\n", envp->data);
		envp = envp->next;
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


void	ft_unset(t_envp **data, t_minishell *av)
{
	t_envp *current;
	t_envp *prev;
	int		i;

	current = *data;
	prev = NULL;
	if (av->args[1] == NULL)
		return;
	i = ft_strlen(av->args[1]);
	if (av->args[1] != NULL)
	{
		while(current != NULL)
		{
			if (ft_strncmp(current->data, av->args[1], i) == 0)
			{
				if (prev == NULL)
				{
					*data = current->next;
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

void	ft_export(t_envp **data, t_minishell *av)
{
	t_envp *current;
	int		i;
	char	*tmp;

	current = *data;
	if (av->args[1] == NULL)
	{
		print_export(*data);
		return;
	}
	else
	{
		tmp = ft_get_the_Key(av->args[1]);
		i = ft_strlen(tmp);
		if (ft_strchr(av->args[1], '=') == NULL)
			return;
		else
		if (ft_strncmp(current->data, tmp, i) == 0)
		{
			*data = remove_env_variable(*data, tmp);
			*data = add_env_variable(*data, av->args[1]);
		}
		else
			*data = add_env_variable(*data, av->args[1]);
	}
}

t_envp *ft_exit(t_envp *data, t_minishell *av)
{
	int	i;

	i = 0;
	if (ft_strcmp(av->args[1], "exit") == 0)
	{
		while (data != NULL)
		{
			free(data->data);
			free(data);
			data = data->next;
		}
		free (av);
		printf("exiting...\n");
		exit(0);
	}
	return (data);
}

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
		pwd = getcwd(NULL, 0);
		tmp = ft_strjoin("PWD=", pwd);
		if (!tmp)
			return (NULL);
		data = remove_env_variable(data, "PWD");
		data = add_env_variable(data, tmp);
		free(tmp);
		free(oldpwd);
		free(pwd);
	}
	// printf("%s\n", getcwd(NULL, 0));
	return (data);
}

// int main(int ac, char **av, char **enviroment)
// {
// 	t_minishell *arg;
// 	t_envp	*hold;

// 	arg = (t_minishell *)malloc(sizeof(t_minishell));
// 	arg->args = av;
// 	if (ac > 1)
// 	{
// 	hold = dup_env(enviroment);
	// ft_pwd(av, hold);
	// ft_env(av, hold);
	// ft_echo(ac, arg);
// 	//printf("Before unset:\n");
// 	// while (hold != NULL) {
//     //     printf("%s\n", hold->data);
//     //     hold = hold->next;
//     // }

//     hold = ft_unset(hold, arg);
// 	// printf("before cd\n");
// 	// while (hold != NULL) {
// 	// 	printf("%s\n", hold->data)
// 	// 	hold = hold->next;
// 	// }
// 	hold = ft_change_directory(hold, arg);
// 	hold = ft_export(hold, arg);
// 	hold = ft_exit(hold, arg);
// 	// printf("%s\n", getcwd(NULL, 0));
// 	// printf("after\n");
// 	// while (hold != NULL) {
// 	// 	printf("%s\n", hold->data);
// 	// 	hold = hold->next;
// 	// }
// // //	hold = ft_export(hold,arg);
//         // printf("After unset:\n");
//         // while (hold != NULL) {
//         //     printf("%s\n", hold->data);
//         //     hold = hold->next;
//         // }
// 	}
// }

void	free_double(char **str)
{
	int i = 0;

	while (str && str[i])
	{
		free (str[i]);
		i++;
	}
	if (str)
		free (str);
}

void	parse(char **av, t_minishell *arg)
{
	t_minishell *current;
	char		**splt_args;
	char		**splt_cmd;

	splt_args = ft_split(av[1], '|');
	splt_cmd = NULL;
	current = arg;
	int i = 0;

	while (splt_args[i] != NULL)
	{
		splt_cmd = ft_split(splt_args[i], ' ');
		current->cmd_path = splt_cmd[0];
		current->args = splt_cmd + 1;
		if (splt_args[i + 1])
		{
			current->pipe = true;
			current->next = (t_minishell *)malloc(sizeof(t_minishell));
			current->next->prev = current;
			current = current->next;
		}
		else
			current->pipe = false;
		i++;
	}
	free_double(splt_args);
}

void	pipes_handle(t_minishell *arg, int old_fd, int *fd)
{
	dup2(old_fd, STDIN_FILENO);
	if (old_fd)
		close(old_fd);
	if (arg->pipe == true)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
}

void	execbuiltin(t_minishell *arg, char *cmd, t_envp *hold)
{
	if (!ft_strcmp(cmd, "env"))
		ft_env(hold);
	else if (!ft_strcmp(cmd, "export"))
		ft_export(&hold, arg);
	else if (!ft_strcmp(cmd, "unset"))
		ft_unset(&hold, arg);
	if (arg->prev->pipe == true)
		exit(0);
}

int main(int ac, char **av, char **envp)
{
	t_minishell *arg;
	t_envp	*hold;
	int		fd[2];
	pid_t	pid;
	int		cmd_n;
	bool	is_builtin;
	int		old_fd;

	arg = (t_minishell *)malloc(sizeof(t_minishell));
	hold = dup_env(envp);
	arg->prev = arg;
	parse(av, arg);
	// while (arg)
	// {
	// 	printf("command's path : %s\n", arg->cmd_path);
	// 	printf("argumnets : \n");
	// 	int i = 0;
	// 	while (arg->args[i])
	// 	{
	// 		printf("%s\n", arg->args[i]);
	// 		i++;
	// 	}
	// 	printf("pipe : ");
	// 	arg->pipe ? printf("TRUE\n") : printf("FALSE\n");
	// 	arg = arg->next;
	// }

	cmd_n = 0;
	pid = 0;
	is_builtin = false;
	old_fd = 0;
	while (arg)
	{
		if (!ft_strcmp(arg->cmd_path, "echo") || !ft_strcmp(arg->cmd_path, "env")
			|| !ft_strcmp(arg->cmd_path, "cd") || !ft_strcmp(arg->cmd_path, "unset")
			|| !ft_strcmp(arg->cmd_path, "export") || !ft_strcmp(arg->cmd_path, "exit")
			|| !ft_strcmp(arg->cmd_path, "pwd"))
			is_builtin = true;
		if (arg->prev->pipe == true || is_builtin == false)
		{
			pipe(fd);
			cmd_n++;
			pid = fork();
			if (pid == 0)
			{
				pipes_handle(arg, old_fd, fd);
				if (is_builtin == true)
					execbuiltin(arg, arg->cmd_path, hold);
				else
					execve(arg->cmd_path, arg->args, envp);
			}
			close(fd[1]);
			if (old_fd)
				close(old_fd);
			if (arg->pipe == true)
				old_fd = fd[0];
		}
		else
		execbuiltin(arg, arg->cmd_path, hold);
		arg = arg->next;
		is_builtin = false;
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