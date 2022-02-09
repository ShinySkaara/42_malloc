/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:39:37 by alalonzo          #+#    #+#             */
/*   Updated: 2022/02/08 14:14:06 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static t_node	*mlc_get_next_ptr(t_node *min, t_node *max, t_node *n)
{
	t_node	*p;

	p = n;
	while (p)
	{
		if (p > max && p->free == 0)
			max = p;
		p = p->next;
	}
	p = n;
	while (p)
	{
		if (p > min && p < max && p->free == 0)
		{
			max = p;
			p = n;
		}
		p = p->next;
	}
	return (max);
}

static void	mlc_print_addr(size_t add)
{
	int		i;
	char	*ref;
	char	res[32];

	i = 0;
	ref = "0123456789ABCDEF";
	while (add)
	{
		res[i] = ref[add % 16];
		add /= 16;
		i++;
	}
	res[i] = '\0';
	ft_strrev(res);
	ft_putstr("0x");
	ft_putstr(res);
}

static void	mlc_print_type_range_ext(t_node *n)
{
	mlc_print_addr((size_t)n + sizeof(t_node));
	ft_putstr(" - ");
	mlc_print_addr((size_t)n + sizeof(t_node) + n->size);
	ft_putstr(" : ");
	ft_putnbr(n->size);
	ft_putstr(" octets\n");
}

static int	mlc_print_type_range(t_node *n, int type)
{
	int		r;

	if (n->size <= TINY)
		r = 1;
	else if (n->size <= SMALL)
		r = 2;
	else
		r = 3;
	if (r != type)
	{
		if (r == 1)
			ft_putstr("TINY : ");
		if (r == 2)
			ft_putstr("SMALL : ");
		if (r == 3)
			ft_putstr("LARGE : ");
		mlc_print_addr((size_t)n);
		ft_putchar('\n');
	}
	mlc_print_type_range_ext(n);
	return (r);
}

void	show_alloc_mem(void)
{
	t_env	*env;
	t_sam	sam;

	env = mlc_start();
	sam.min = NULL;
	sam.max = NULL;
	sam.type = 0;
	sam.size = 0;
	while (1)
	{
		sam.max = mlc_get_next_ptr(sam.min, sam.max, env->lst);
		if (sam.min == sam.max)
			break ;
		sam.type = mlc_print_type_range(sam.max, sam.type);
		sam.size += sam.max->size;
		sam.min = sam.max;
	}
	if (sam.size)
	{
		ft_putstr("total : ");
		ft_putnbr(sam.size);
		ft_putstr(" octets\n");
	}
}
