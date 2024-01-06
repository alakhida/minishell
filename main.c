#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int		echo_opt(const char *av)
{
	int		i;

	i = 1;
	if (av[0] != '-')
		return (1);
	while (av[i])
		{
			if (av[i] != 'n')
				return (1);
			i++;
		}
	return (0);
}

void ft_echo(int argc, t_minishell *av) 
{
    int newline;
	int		i;

	newline = 0;
	i = 2;
	if (ft_strcmp(av->args[1], "echo") == 0 && av->args[2] != NULL)
	{
	//	i += 1;
		if (echo_opt(av->args[2]) == 0)
			{
			i+= 1;
			newline = 1;
			}
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

int main(int ac, char **av, char **enviroment)
{
	t_minishell *arg;
	arg = (t_minishell *)malloc(sizeof(t_minishell));
	arg->args = av;
	(void)enviroment;
	if (ac > 1)
	{
		ft_echo(ac, arg);
	}
}