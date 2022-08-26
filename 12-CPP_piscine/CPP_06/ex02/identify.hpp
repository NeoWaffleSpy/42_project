/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:03:34 by ncaba             #+#    #+#             */
/*   Updated: 2022/08/26 19:03:34 by ncaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

// LIBS ========================================================================
# include <iostream>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
// =============================================================================

// PROTOYPES ===================================================================
void identify_from_pointer(Base * p);
void identify_from_reference( Base & p);
// =============================================================================

#endif