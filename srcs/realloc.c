/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:31:26 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:41:56 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "malloc.h"
#include "libft.h"

static size_t	mlc_align(size_t size, int a)
{
	size_t	s;

	s = 0;
	while (s < size)
		s += a;
	return (s);
}

static void	*mlc_realloc_ext(void *ptr, size_t size, t_node *n)
{
	void	*p;

	if (n->next && n->next->free)
		mlc_fuse_node(n, n->next);
	if (n->size < size)
	{
		p = malloc(size);
		if (p)
		{
			p = ft_memcpy(p, ptr, n->size);
			free(ptr);
			return (p);
		}
	}
	mlc_split_node(size, n);
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_env	*env;
	t_node	*n;

	env = mlc_start();
	n = mlc_verify_ptr(ptr, env->lst);
	if (size)
	{
		size = mlc_align(size, 16);
		if (ptr == NULL)
			ptr = malloc(size);
		if (n && n->free == 0)
			ptr = mlc_realloc_ext(ptr, size, n);
	}
	else
	{
		free(ptr);
	}
	return (ptr);
}
