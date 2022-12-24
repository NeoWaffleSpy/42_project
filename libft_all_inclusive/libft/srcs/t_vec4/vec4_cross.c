/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:23 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:32:24 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"
#include <math.h>

/*
**	FST BUT DUNNO IF IT ACTUALLY WORKS
**	result = _mm_sub_ps(
**	_mm_mul_ps(b.sse, _mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 0, 2, 1))),
**	_mm_mul_ps(a.sse, _mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 0, 2, 1)))
**	);
**	return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1 ));
*/

t_vec4	vec4_cross(const t_vec4 a, const t_vec4 b)
{
	t_vec4		res;

	res.sse = _mm_sub_ps(
			_mm_mul_ps(
				_mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 1, 0, 2))),
			_mm_mul_ps(
				_mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 1, 0, 2)),
				_mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 0, 2, 1))));
	return (res);
}
