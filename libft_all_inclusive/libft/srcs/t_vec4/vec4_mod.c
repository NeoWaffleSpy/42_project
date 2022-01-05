/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:33:06 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:33:08 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"
#include <math.h>

float		vec4_mod(const t_vec4 a)
{
	return (sqrtf(vec4_dot(a, a)));
}

float		vec4_mod2(const t_vec4 a)
{
	return (vec4_dot(a, a));
}
