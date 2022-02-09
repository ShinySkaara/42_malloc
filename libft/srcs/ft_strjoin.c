/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:46 by alalonzo          #+#    #+#             */
/*   Updated: 2021/02/22 16:41:13 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_a;
	int		len_b;
	char	*ptr;

	len_a = ft_strlen(s1);
	len_b = ft_strlen(s2);
	ptr = ft_stralloc(len_a + len_b);
	if (ptr)
	{
		ft_strcpy(ptr, s1);
		ft_strcpy(ptr + len_a, s2);
	}
	return (ptr);
}
