/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:47:00 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:46:32 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "malloc.h"
#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	size_t	s;
	void	*p;

	s = nmemb * size;
	if (s)
	{
		p = malloc(s);
		if (p)
			ft_memset(p, 0, s);
		return (p);
	}
	return (NULL);
}
