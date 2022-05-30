/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42/fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 15:34:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_triangle_normale(t_ray *ray, t_obj *obj)
{
	t_v3	ab;
	t_v3	ac;

	ab = sub_vector(obj->b, obj->a);
	ac = sub_vector(obj->c, obj->a);
	ray->normale = cross_product(ab, ac);
}

static bool pts_lies_in_triangle(t_ray *ray, t_obj *obj)
{
	t_v3 edge_ab;
	t_v3 edge_bc;
	t_v3 edge_ca;
	t_v3 c[3];

	edge_ab = sub_vector(obj->b, obj->a);
	edge_bc = sub_vector(obj->c, obj->b);
	edge_ca = sub_vector(obj->a, obj->c);
	c[0] = sub_vector(ray->intersection, obj->a);
	c[1] = sub_vector(ray->intersection, obj->b);
	c[2] = sub_vector(ray->intersection, obj->c);
	if (scalar_product(ray->normale, cross_product(edge_ab, c[0])) > 0
		&& scalar_product(ray->normale, cross_product(edge_bc, c[1])) > 0
		&& scalar_product(ray->normale, cross_product(edge_ca, c[2])) > 0)
		return (true);
	return (false);
}

bool	intersection_triangle(t_obj *obj, t_ray *ray)
{
	double d;

	get_triangle_normale(ray, obj);
	d = scalar_product(ray->normale, obj->a);
	if (!d)
		return (false);
	ray->t = -(scalar_product(ray->normale, ray->position) + d) / scalar_product(ray->normale, ray->direction);
	if (ray->t < 0)
		return (false);
	ray->intersection = mul_vector(ray->direction, ray->t); // pts d'intersection du plan du triangle
	return (pts_lies_in_triangle(ray, obj));//check si pts est a l'interieur du triangle
}