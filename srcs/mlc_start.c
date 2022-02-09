/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlc_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalonzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:32:19 by alalonzo          #+#    #+#             */
/*   Updated: 2022/01/31 16:57:22 by alalonzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "malloc.h"

t_env	*mlc_start(void)
{
	static t_env	env;

	if (env.init == 0)
	{
		env.init = 1;
		env.ps = getpagesize();
	}
	return (&env);
}
