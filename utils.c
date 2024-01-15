#include "minishell.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	char	str;
// 	char	*alt;
// 	int		i;

// 	i = 0;
// 	alt = (char *)s;
// 	str = c;
// 	while (alt[i] != str)
// 	{
// 		if (alt[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	return ((char *)alt + i);
// }

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while ((s1[i] != '\0' || s2[i] != '\0') && n--)
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (0);
// }
// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] && s2[i])
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }

// void	ft_putstr(char *s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		write(1, &s[i++], 1);
// }

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

// int	ft_strlen(char *s)
// {
// 	int		i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(char *src)
// {
// 	char	*dst;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = ft_strlen(src);
// 	dst = (char *)malloc(sizeof(char) * len  + 1);
// 	if (!dst)
// 		return (NULL);
// 	while (src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }

// char	*ft_strtok(char *str, char *delim)
// {
// 	static char	*last = NULL;
// 	char		*res;
// 	int			i;

// 	i = 0;
// 	if (str)
// 		last = str;
// 	if (!last)
// 		return (NULL);
// 	while (last[i] && !ft_strchr(delim, last[i]))
// 		i++;
// 	if (last[i] == '\0')
// 	{
// 		res = last;
// 		last = NULL;
// 		return (res);
// 	}
// 	last[i] = '\0';
// 	res = last;
// 	last = last + i + 1;
// 	return (res);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char			*dst;
// 	unsigned int	t;
// 	unsigned int	i;

// 	t = count * size;
// 	dst = malloc(t);
// 	if (!dst)
// 		return (NULL);
// 	i = 0;
// 	while (t--)
// 	{
// 		dst[i] = 0;
// 		i++;
// 	}
// 	return ((void *)dst);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*r;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 	{
// 		s1 = malloc(1);
// 		s1[0] = '\0';
// 	}
// 	r = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
// 	if (r == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		r[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j])
// 		r[i++] = s2[j++];
// 	//free(s1);
// 	return (r);
// }