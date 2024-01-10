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
// t_envp *ft_unset(t_envp *data, t_minishell *av) {
//     int i = ft_strlen(av->args[2]);

//     if (ft_strcmp(av->args[1], "unset") == 0 && av->args[2] != NULL) {
//         t_envp *current = data;
//         t_envp *prev = NULL;

//         while (current != NULL) {
//             if (ft_strncmp(current->data, av->args[2], i) == 0) {
//                 if (prev == NULL) {
//                     data = current->next;
//                 } else {
//                     prev->next = current->next;
//                 }
//                 free(current);
//                 break;
//             } else {
//                 prev = current;
//                 current = current->next;
//             }
//         }
//     }

//     return data;
// }




// char *ft_get_the_Key(char *envp)
// {
// 	int		i = 0;
// 	char	*key;

// 	while(envp[i])
// 	{
// 		if (envp[i] == '=')
// 			break;
// 		i++;
// 	}
// 	key = malloc(sizeof(char) * i);
// 	i = 0;
// 	while(envp[i])
// 	{
// 		if (envp[i] == '=')
// 			break;
// 		key[i] = envp[i];
// 		i++;
// 	}
// 	return (key);
// }



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

