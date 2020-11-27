/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcadiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:17:02 by pcadiot           #+#    #+#             */
/*   Updated: 2016/11/13 18:17:05 by pcadiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstadd(t_list **alst, t_list *new)
{
	t_list		*tmp;

	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		*alst = new;
		new->next = tmp;
	}
}
