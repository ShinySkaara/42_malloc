/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:52:12 by alalonzo          #+#    #+#             */
/*   Updated: 2020/12/03 17:56:30 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr_a;
	char	*ptr_b;

	ptr_a = (char *)s;
	ptr_b = NULL;
	while (*ptr_a && *ptr_a != c)
	{
		ptr_a++;
	}
	if (*ptr_a == c)
	{
		ptr_b = ptr_a;
	}
	return (ptr_b);
}
