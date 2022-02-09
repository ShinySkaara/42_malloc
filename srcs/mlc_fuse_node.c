/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_fuse_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:21:50 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:55:47 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "malloc.h"

void	mlc_fuse_node(t_node *a, t_node *b)
{
	int	ma;
	int	mb;

	ma = (size_t)a % getpagesize();
	mb = (size_t)b % getpagesize();
	if ((ma == 0 && mb == 0) || (ma == 1 && mb == 0))
	{
		a->next = b->next;
		a->size += b->size + sizeof(t_node);
		if (a->next)
			a->next->prev = a;
	}
}
