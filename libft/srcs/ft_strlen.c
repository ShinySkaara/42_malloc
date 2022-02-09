/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:49:39 by alalonzo          #+#    #+#             */
/*   Updated: 2020/12/03 18:00:58 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		ptr++;
	}
	return (ptr - s);
}
