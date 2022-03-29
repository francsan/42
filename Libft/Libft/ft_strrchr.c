/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:58:02 by francsan          #+#    #+#             */
/*   Updated: 2022/02/18 17:22:31 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*ini;

	ini = s;
	i = ft_strlen(s);
	s = (s + i);
	while (c > 127)
		c -= 128;
	while (*s != *ini && c != *s)
		s--;
	if (*s == c)
		return ((char *)s);
	return (0);
}
