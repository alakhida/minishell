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

int main(int ac, char **av, char **enviroment)
{
	//t_minishell *arg;
	(void)ac;
	t_envp	*hold;

	hold = (t_envp *)malloc(sizeof(t_envp));
	(void)av;
	hold = dup_env(enviroment);
	hold = remove_env_variable(hold, "COLORTERM");
		while (hold != NULL)
		{
			printf("%s\n", hold->data);
			hold = hold->next;
		}
}
	//arg = (t_minishell *)malloc(sizeof(t_minishell));
	//arg->args = av;
	//	ft_echo(ac, arg);
	// if (ac > 1)
	// {