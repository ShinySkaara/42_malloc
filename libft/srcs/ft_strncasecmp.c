/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:53:41 by alalonzo          #+#    #+#             */
/*   Updated: 2021/02/22 16:28:42 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n)
	{
		if (ft_tolower(*s1) - ft_tolower(*s2) != 0)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (ft_tolower(*s1) - ft_tolower(*s2));
}
