/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:34:51 by ncaba             #+#    #+#             */
/*   Updated: 2022/06/06 21:53:31 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP
# include "libft/include/ft_lib.h"


void	sa(t_list **a, t_list **b, int dual);
void	sb(t_list **a, t_list **b, int dual);
void	ss(t_list **a, t_list **b, int dual);
void	pa(t_list **a, t_list **b, int dual);
void	pb(t_list **a, t_list **b, int dual);
void	ra(t_list **a, t_list **b, int dual);
void	rb(t_list **a, t_list **b, int dual);
void	rr(t_list **a, t_list **b, int dual);
void	rra(t_list **a, t_list **b, int dual);
void	rrb(t_list **a, t_list **b, int dual);
void	rrr(t_list **a, t_list **b, int dual);
t_list	*get_chain(t_list *a, int iter);
void	call_error(char *error, char *value);
void	call_info(char *info, char *value);
int		check_sorted(t_list **a, int rev);
int		get_content(t_list *list, int place);
void	sort_3(t_list **a, t_list **b);
void	sort_4_5(t_list **a, t_list **b);
void	sort_big(t_list **a, t_list **b);
void	sort_big_index(t_list **a, t_list **b);
void	sort_big_2(t_list **a, t_list **b);
void	sort_big_3_1(t_list **a, t_list **b, int k);
void	sort_big_3_2(t_list **a, t_list **b, int k);
void	sort_big_new(t_list **a, t_list **b);
void	print_iter(t_list *lst);

#endif
