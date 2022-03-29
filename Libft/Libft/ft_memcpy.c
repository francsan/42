/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:31:56 by francsan          #+#    #+#             */
/*   Updated: 2022/02/24 14:47:34 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	while (n > 0)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		n--;
	}
	return (dest);
}
