/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:00:06 by alalonzo          #+#    #+#             */
/*   Updated: 2021/03/27 17:07:02 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hexdump(void *data, size_t size)
{
	size_t			i;
	int				n;
	char			*ref;
	unsigned char	*s;

	i = 0;
	ref = "0123456789abcdef";
	s = (unsigned char *)data;
	while (i < size)
	{
		n = s[i] / 16;
		write(1, &ref[n], 1);
		n = s[i] % 16;
		write(1, &ref[n], 1);
		i++;
	}
}
