/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_abs_sqr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:05 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:32:07 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

/*
**	Creates a mask that removes the sign bit
*/

t_vec4		vec4_abs(t_vec4 a)
{
	__m128		mask;

	mask = _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF));
	a.sse = _mm_and_ps(a.sse, mask);
	return (a);
}

t_vec4		vec4_sqrt(t_vec4 a)
{
	a.sse = _mm_sqrt_ps(a.sse);
	return (a);
}

t_vec4		vec4_square(t_vec4 a)
{
	return (vec4_mul(a, a));
}
