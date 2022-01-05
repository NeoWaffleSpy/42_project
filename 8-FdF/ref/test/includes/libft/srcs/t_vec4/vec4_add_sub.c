/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_add_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:15 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:32:17 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

t_vec4		vec4_add(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_add_ps(a.sse, b.sse);
	return (a);
}

t_vec4		vec4_addf(t_vec4 a, const float b)
{
	return (vec4_add(a, vec4_newf(b)));
}

t_vec4		vec4_sub(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_sub_ps(a.sse, b.sse);
	return (a);
}

t_vec4		vec4_subf(t_vec4 a, const float b)
{
	a.sse = _mm_sub_ps(a.sse, vec4_newf(b).sse);
	return (a);
}

t_vec4		vec4_fsub(const float a, t_vec4 b)
{
	t_vec4		res;

	res.sse = _mm_sub_ps(vec4_newf(a).sse, b.sse);
	return (res);
}
