/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:32 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:32:33 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

t_vec4		vec4_div(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_div_ps(a.sse, b.sse);
	return (a);
}

t_vec4		vec4_divf(t_vec4 a, const float b)
{
	a.sse = _mm_div_ps(a.sse, vec4_newf(b).sse);
	return (a);
}
