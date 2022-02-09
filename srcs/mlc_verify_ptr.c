/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_verify_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:19:56 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/25 15:30:58 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_node	*mlc_verify_ptr(void *ptr, t_node *n)
{
	while (n)
	{
		if (ptr == (void *)n + sizeof(t_node))
			break ;
		n = n->next;
	}
	return (n);
}
