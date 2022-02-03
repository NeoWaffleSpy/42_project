/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrisics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:31:46 by ncaba             #+#    #+#             */
/*   Updated: 2022/01/05 13:36:18 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTRISICS_H
# define INTRISICS_H
# include <inttypes.h>
# include <string.h>
# include <x86intrin.h>

# ifdef __AVX__
#  define LFT_AVX 1
# else
#  define LFT_AVX 0
# endif
# ifdef __SSE2__
#  define LFT_SSE2 1
# else
#  define LFT_SSE2 0
# endif

# define GNL_BUFF_SIZE 32768
# define GNL_FLUSH (char**)INTPTR_MAX

typedef uint32_t	t_queued;
typedef void		t_listed;
typedef int			t_vected;

typedef int			t_map_key;
typedef long double	t_map_data;

typedef struct	s_queue
{
	int				start;
	int				end;
	int				size;
	t_queued		*arr;
}				t_queue;

typedef union	u_vec4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	}				flt;
	__m128			sse __attribute__((aligned(16)));
}				t_vec4;

typedef struct	s_vector
{
	t_vected		*arr;
	size_t			len;
	size_t			mem;
}				t_vector;

typedef struct	s_garbage
{
	void			**pointers;
	size_t			arr_len;
	size_t			mem_len;
}				t_garbage;

enum			e_rbtn_color
{
	BLACK2 = 0,
	RED2
};

typedef struct	s_rbtmap
{
	t_map_key			key;
	t_map_data			*dat;
	enum e_rbtn_color	col;
	struct s_rbtmap		*lft;
	struct s_rbtmap		*rgt;
	struct s_rbtmap		*up;
}				t_rbtmap;

t_vec4		vec4_abs(t_vec4 a);
t_vec4		vec4_sqrt(t_vec4 a);
t_vec4		vec4_square(t_vec4 a);
t_vec4		vec4_add(t_vec4 a, const t_vec4 b);
t_vec4		vec4_addf(t_vec4 a, const float b);
t_vec4		vec4_sub(t_vec4 a, const t_vec4 b);
t_vec4		vec4_subf(t_vec4 a, const float b);
t_vec4		vec4_fsub(const float a, t_vec4 b);
t_vec4		vec4_cross(const t_vec4 a, const t_vec4 b);
t_vec4		vec4_div(t_vec4 a, const t_vec4 b);
t_vec4		vec4_divf(t_vec4 a, const float b);
__m128		intrin__sse2_dot(const t_vec4 a, const t_vec4 b);
t_vec4		vec4_dotvec(const t_vec4 a, const t_vec4 b);
float		vec4_dot(const t_vec4 a, const t_vec4 b);
t_vec4		vec4_matmul(const t_vec4 mat[4], const t_vec4 vec);
void		vec4_newmat_aa(t_vec4 mat[4], const float f[4][4]);
void		vec4_newmat_a(t_vec4 mat[4], const float f[16]);
float		vec4_mod(const t_vec4 a);
float		vec4_mod2(const t_vec4 a);
t_vec4		vec4_mul(t_vec4 a, const t_vec4 b);
t_vec4		vec4_mulf(t_vec4 a, const float b);
t_vec4		vec4_newf(const float f);
t_vec4		vec4_newv(const float x, const float y, const float z,
				const float w);
t_vec4		vec4_newzero(void);
t_vec4		vec4_newnan(void);
t_vec4		vec4_newa(const float f[4]);
t_vec4		vec4_newa3(const float f[3], float w);
t_vec4		vec4_norm(const t_vec4 v);

#endif
