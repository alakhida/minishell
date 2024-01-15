/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:46:41 by alakhida          #+#    #+#             */
/*   Updated: 2022/10/25 14:39:46 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	s = 0;
	e = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		s = (i++) + 1;
	if (s >= ft_strlen(s1))
		return ((char *)ft_calloc(sizeof(char), 1));
	i = ft_strlen(s1) - 1;
	while (i && s1[i] && ft_strchr(set, s1[i]))
		e = (i--) - 1;
	return (ft_substr(s1, s, (e - s + 1)));
}
