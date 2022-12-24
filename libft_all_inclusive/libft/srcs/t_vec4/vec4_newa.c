/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_newa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:33:29 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:33:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

t_vec4		vec4_newa(const float f[4])
{
	t_vec4		res;

	res.sse = _mm_load_ps(f);
	return (res);
}

t_vec4		vec4_newa3(const float f[3], float w)
{
	return (vec4_newv(f[0], f[1], f[2], w));
}
