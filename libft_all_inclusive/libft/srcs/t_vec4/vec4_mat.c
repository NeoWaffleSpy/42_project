/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:32:57 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:33:00 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/intrisics.h"

/*
**	Here the matrix is defined by 4 vec4, each representing a row.
*/

t_vec4	vec4_matmul(const t_vec4 mat[4], const t_vec4 vec)
{
	return (vec4_newv(
			vec4_dot(mat[0], vec),
			vec4_dot(mat[1], vec),
			vec4_dot(mat[2], vec),
			vec4_dot(mat[3], vec)));
}

void		vec4_newmat_aa(t_vec4 mat[4], const float f[4][4])
{
	int		i;

	i = -1;
	while (++i < 4)
		mat[i] = vec4_newa(f[i]);
}

void		vec4_newmat_a(t_vec4 mat[4], const float f[16])
{
	mat[0] = vec4_newa(&f[0]);
	mat[1] = vec4_newa(&f[4]);
	mat[2] = vec4_newa(&f[8]);
	mat[3] = vec4_newa(&f[12]);
}
