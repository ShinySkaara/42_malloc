/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:51:19 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:45:26 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/mman.h>
#include "malloc.h"

static size_t	mlc_align(size_t size, int a)
{
	size_t	s;

	s = 0;
	while (s < size)
		s += a;
	return (s);
}

static void	*mlc_get_ptr(size_t size, t_node *n)
{
	while (n)
	{
		if (n->free && n->size >= size)
		{
			n->free = 0;
			mlc_split_node(size, n);
			return ((void *)n + sizeof(t_node));
		}
		n = n->next;
	}
	return (NULL);
}

static t_node	*mlc_new_node(size_t size, int ps)
{
	size_t	s;
	t_node	*new;

	if (size <= TINY)
		s = 100 * (sizeof(t_node) + TINY);
	else if (size <= SMALL)
		s = 100 * (sizeof(t_node) + SMALL);
	else
		s = sizeof(t_node) + size;
	s = mlc_align(s, ps);
	new = mmap(NULL, s, PROT_READ_WRITE, MAP_PRIVATE_ANONYMOUS, -1, 0);
	if (new != MAP_FAILED)
	{
		new->free = 1;
		new->size = s - sizeof(t_node);
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

void	mlc_add_node(t_node *node, t_env *env)
{
	node->next = env->lst;
	env->lst = node;
	if (node->next)
		node->next->prev = node;
}

void	*malloc(size_t size)
{
	t_env	*env;
	t_node	*new;
	void	*ptr;

	env = mlc_start();
	size = mlc_align(size, 16);
	ptr = mlc_get_ptr(size, env->lst);
	if (ptr == NULL)
	{
		new = mlc_new_node(size, env->ps);
		if (new)
		{
			mlc_add_node(new, env);
			ptr = mlc_get_ptr(size, new);
		}
	}
	return (ptr);
}
