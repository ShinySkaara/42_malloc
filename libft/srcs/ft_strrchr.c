/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:49:19 by alalonzo          #+#    #+#             */
/*   Updated: 2020/12/03 17:59:04 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr_a;
	char	*ptr_b;

	ptr_a = (char *)s;
	ptr_b = NULL;
	while (*ptr_a)
	{
		if (*ptr_a == c)
		{
			ptr_b = ptr_a;
		}
		ptr_a++;
	}
	if (*ptr_a == c)
	{
		ptr_b = ptr_a;
	}
	return (ptr_b);
}
