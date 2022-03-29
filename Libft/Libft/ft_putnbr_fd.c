/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:29:03 by francsan          #+#    #+#             */
/*   Updated: 2022/02/23 17:45:26 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	nbr = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = n * -1;
	}
	if (nbr == 0)
		nbr = (unsigned int)n;
	if (nbr < 10)
	{
		nbr += 48;
		write(fd, &nbr, 1);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}
