/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:14:17 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:49:36 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/mman.h>
#include "malloc.h"

static void	mlc_del_node(t_node *n, t_env *env)
{
	t_node	*prev;

	prev = n->prev;
	if (munmap(n, n->size + sizeof(t_node)) == 0)
	{
		if (prev)
			prev->next = NULL;
		else
			env->lst = NULL;
	}
}

void	free(void *ptr)
{
	t_env	*env;
	t_node	*n;

	env = mlc_start();
	if (ptr)
	{
		n = mlc_verify_ptr(ptr, env->lst);
		if (n)
		{
			n->free = 1;
			if (n->prev && n->prev->free)
			{
				n = n->prev;
				mlc_fuse_node(n, n->next);
			}
			if (n->next && n->next->free)
				mlc_fuse_node(n, n->next);
			if (n->next == NULL)
				mlc_del_node(n, env);
		}
	}
}
