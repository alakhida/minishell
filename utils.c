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

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src);
	dst = (char *)malloc(sizeof(char) * len  + 1);
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}