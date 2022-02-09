/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:00:16 by alalonzo          #+#    #+#             */
/*   Updated: 2020/12/03 17:58:47 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*ptr;

	ptr = dst;
	while (*src && n)
	{
		*ptr++ = *src++;
		n--;
	}
	while (n)
	{
		*ptr++ = '\0';
		n--;
	}
	return (dst);
}
