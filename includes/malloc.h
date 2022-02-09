/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:57:17 by alalonzo          #+#    #+#             */
/*   Updated: 2022/02/07 02:36:59 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_h

# define PROT_READ_WRITE (PROT_READ | PROT_WRITE)
# define MAP_PRIVATE_ANONYMOUS (MAP_PRIVATE | MAP_ANONYMOUS)
# define TINY 16
# define SMALL 128

# include <stddef.h>

typedef struct		s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	size_t			size;
	char			free;
}					t_node;

typedef struct	s_sam
{
	t_node		*min;
	t_node		*max;
	int			type;
	size_t		size;
}				t_sam;

typedef struct	s_env
{
	int			init;
	int			ps;
	t_node		*lst;
}				t_env;

t_env	*mlc_start(void);
void	mlc_split_node(size_t size, t_node *n);
void	mlc_fuse_node(t_node *a, t_node *b);
t_node	*mlc_verify_ptr(void *ptr, t_node *n);

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	*calloc(size_t nmemb, size_t size);
void	free(void *ptr);
void	show_alloc_mem(void);

#endif
