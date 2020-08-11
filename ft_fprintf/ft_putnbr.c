/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoure <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 09:09:07 by motoure           #+#    #+#             */
/*   Updated: 2020/02/23 09:09:10 by motoure          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lprintf.h"

void			ft_putnbr(int fd, int n)
{
	int sign;

	n == -2147483648 ? write(fd ,"-2147483648", 11) : 0;
	n == 0 ? write(fd, "0", 1) : 0;
	if (n == -2147483648)
		return ;
	if (n == 0)
		return ;
	sign = (n > 0 ? 0 : 1);
	n > 0 ? 0 : ft_putchar(fd, '-');
	n = (n > 0 ? n : n * -1);
	if (n > 9)
		ft_putnbr(fd, n / 10);
	ft_putchar(fd, n % 10 + '0');
}
