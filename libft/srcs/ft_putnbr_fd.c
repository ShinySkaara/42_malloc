/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:00:00 by alalonzo          #+#    #+#             */
/*   Updated: 2020/12/01 16:04:30 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			neg;
	int			len;
	int			i;
	char		buf[16];

	nb = (long int)n;
	neg = (nb < 0);
	if (neg)
	{
		buf[0] = '-';
		nb = -nb;
	}
	len = ft_numlen(nb);
	i = len;
	while (i--)
	{
		buf[i + neg] = (nb % 10) + '0';
		nb = nb / 10;
	}
	write(fd, buf, len + neg);
}
