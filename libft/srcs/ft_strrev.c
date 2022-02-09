/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 00:47:30 by alalonzo          #+#    #+#             */
/*   Updated: 2020/11/28 01:42:29 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *s)
{
	char	*ptr_a;
	char	*ptr_b;
	char	c;

	ptr_a = s;
	ptr_b = s;
	while (*ptr_b)
	{
		ptr_b++;
	}
	ptr_b--;
	while (ptr_a < ptr_b)
	{
		c = *ptr_a;
		*ptr_a = *ptr_b;
		*ptr_b = c;
		ptr_a++;
		ptr_b--;
	}
	return (s);
}
