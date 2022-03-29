/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:35:57 by francsan          #+#    #+#             */
/*   Updated: 2022/02/20 14:36:03 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2)
	{
		if (n > 1)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (0);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
