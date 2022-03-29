/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:25:11 by francsan          #+#    #+#             */
/*   Updated: 2022/03/07 15:17:23 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	mem_size(char const *s, char c)
{
	int	i;
	int	strs;

	i = 0;
	strs = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			strs++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return ((strs + 1) * sizeof(char *));
}

int	word_size(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return ((i + 1) * sizeof(char));
}

char	**fill_strs(char **strs, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			strs[j] = malloc(word_size(&s[i], c));
			if (!(strs[j]))
				return (NULL);
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				strs[j][k++] = s[i++];
			}
			strs[j++][k] = '\0';
		}
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(mem_size(s, c));
	if (!strs)
		return (NULL);
	strs = fill_strs(strs, s, c);
	return (strs);
}

/*int	main()
{
	int		i;
	char	**strs;

	i = 0;
	//strs = ft_split("lorem ipsum dolor sit amet,  Suspendisse", ' ');
	if (!(strs = ft_split("lorem ipsum dolor sit amet,  Suspendisse", ' ')))
		return (0);
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
}*/