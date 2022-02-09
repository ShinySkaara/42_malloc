/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_split_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:24:01 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:56:21 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "malloc.h"

void	mlc_split_node(size_t size, t_node *n)
{
	t_node	*new;

	if (n->size >= size + sizeof(t_node) + TINY)
	{
		new = (void *)n + sizeof(t_node) + size;
		new->free = 1;
		new->prev = n;
		new->next = n->next;
		new->size = n->size - sizeof(t_node) - size;
		n->next = new;
		n->size = size;
	}
}
