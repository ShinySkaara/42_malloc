/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:57:28 by alalonzo          #+#    #+#             */
/*   Updated: 2021/02/22 14:36:47 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (ft_tolower(*s1) - ft_tolower(*s2) != 0)
			break ;
		s1++;
		s2++;
	}
	return (ft_tolower(*s1) - ft_tolower(*s2));
}
