/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:03:56 by francsan          #+#    #+#             */
/*   Updated: 2022/03/07 15:16:42 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	get_start(char const *str, char const *set)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	if (str[i] == '\0')
		return (0);
	return (i);
}

unsigned int	get_end(char const *str, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
			{
				i--;
				break ;
			}
			j++;
		}
		if ((unsigned int)j == ft_strlen(set))
			break ;
	}
	if (i <= 0)
		return (0);
	return ((unsigned int)i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*newstr;

	if (!s1)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	newstr = malloc(end - start + 1);
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, &s1[start], end - start + 1);
	return (newstr);
}
