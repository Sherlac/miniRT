/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:58:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 10:11:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* A surface normal from a surface at P,
 * is a vector perpendicular to the tangent plane to that surface at P. */

extern inline t_v3	normalize(const t_v3 a)
{
	return (div_vector(a, norm(a)));
}