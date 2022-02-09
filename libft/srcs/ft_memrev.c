/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 22:16:20 by alalonzo          #+#    #+#             */
/*   Updated: 2021/04/02 22:17:58 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrev(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	tmp;

	i = 0;
	size -= 1;
	s = (unsigned char *)ptr;
	while (i < size)
	{
		tmp = s[i];
		s[i] = s[size];
		s[size] = tmp;
		i++;
		size--;
	}
	return (ptr);
}
