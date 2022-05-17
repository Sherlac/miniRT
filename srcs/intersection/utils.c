/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:51:30 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 14:54:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Solution 1 : (-b - racine(delta)) / 2a */
double	t1(double delta, double *abc)
{
	return ((-abc[1] - sqrt(delta)) / (2 * abc[0]));
}

/* Solution 2 : (-b + racine(delta)) / 2a
 * Racine de delta étant positif, on a t2 >= t1 */
double	t2(double delta, double *abc)
{
	return ((-abc[1] + sqrt(delta)) / (2 * abc[0]));
}

/* En supposant que t1 < t2 */
double	min_positive(const double t1, const double t2)
{
	if (t1 > 0)
		return (t1);
	return (t2);
}

/* Position = origine + t * direction */
t_v3	get_position(t_v3 origine, t_v3 direction, double t)
{
	return (add_vector(origine, mul_vector(direction, t)));
}