/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:33:37 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:33:38 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"
#include <math.h>

t_vec4	vec4_norm(const t_vec4 v)
{
	return (vec4_divf(v, vec4_mod(v)));
}