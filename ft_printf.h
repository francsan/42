/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francsan <francsan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:21:22 by francsan          #+#    #+#             */
/*   Updated: 2022/03/15 16:29:43 by francsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putadd(void *p);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_putnbr(int nbr);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr_hex(unsigned int nbr, char c);

#endif