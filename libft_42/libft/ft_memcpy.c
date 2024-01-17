/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:04:29 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/15 03:57:29 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	char		*source;

	dst = (char *)dest;
	source = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
