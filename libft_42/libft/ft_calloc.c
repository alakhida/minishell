/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakhida <alakhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:44:31 by alakhida          #+#    #+#             */
/*   Updated: 2024/01/15 03:47:01 by alakhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*result;
	unsigned int	len;
	unsigned int	i;

	len = count * size;
	result = malloc(len);
	if (!result)
		return (NULL);
	i = 0;
	while (len--)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
