/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:21:49 by francsan          #+#    #+#             */
/*   Updated: 2022/02/23 18:10:57 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (c > 255 || c < 0)
	{
		if (c > 255)
			c -= 256;
		if (c < 0)
			c += 256;
	}
	while (i < (int)n)
	{
		if (*(unsigned char *)(s + i) == c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}

/*int	main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("%s", (char *)ft_memchr(tab, -1, 7));
}*/