/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:33:22 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:33:24 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

/*
**	Hopefully this all gets inlined
**		Please, dear gods of C programming, let the compler inline all of this
**	It was not inlined. Not until now at least hehehe.
**		(C compilers are good but not magical)
*/

t_vec4	vec4_newf(const float f)
{
	t_vec4		res;

	res.sse = _mm_set1_ps(f);
	return (res);
}

t_vec4	vec4_newv(const float x, const float y, const float z, const float w)
{
	t_vec4		res;

	res.sse = _mm_setr_ps(x, y, z, w);
	return (res);
}

t_vec4	vec4_newzero(void)
{
	t_vec4		res;

	res.sse = _mm_setzero_ps();
	return (res);
}

/*
**	not sure about this one
*/

t_vec4	vec4_newnan(void)
{
	t_vec4		res;

	res.sse = _mm_castsi128_ps(_mm_set1_epi32(0x7FC00000));
	return (res);
}
