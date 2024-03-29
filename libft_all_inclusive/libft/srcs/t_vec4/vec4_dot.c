/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:39 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:32:41 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

__m128	intrin__sse2_dot(const t_vec4 a, const t_vec4 b)
{
	__m128		mul;
	__m128		shuf;
	__m128		sums;

	mul = vec4_mul(a, b).sse;
	shuf = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
	sums = _mm_add_ps(mul, shuf);
	shuf = _mm_movehl_ps(shuf, sums);
	sums = _mm_add_ss(sums, shuf);
	return (sums);
}

t_vec4	vec4_dotvec(const t_vec4 a, const t_vec4 b)
{
	t_vec4		res;

	if (LFT_AVX)
		res.sse = _mm_dp_ps(a.sse, b.sse, 0xff);
	else
		res.sse = intrin__sse2_dot(a, b);
	return (res);
}

float		vec4_dot(const t_vec4 a, const t_vec4 b)
{
	return (_mm_cvtss_f32(vec4_dotvec(a, b).sse));
}
