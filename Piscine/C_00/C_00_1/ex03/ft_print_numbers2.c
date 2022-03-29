/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:52:15 by francsan          #+#    #+#             */
/*   Updated: 2022/01/16 14:56:42 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_digit(int a)
{
	a += 48;
	write(1, &a, 1);
}

void ft_print_numbers(void)
{
	int	b;
	int	c;

	b = 0;
	c = 9;
	while (b <= c)
	{
		ft_print_digit(b);
		b = b + 1;
	}
}

int main(void)
{
	ft_print_numbers();
	return (0);
}
