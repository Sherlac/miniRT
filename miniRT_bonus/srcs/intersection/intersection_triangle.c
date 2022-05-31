/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:59:38 by cmariot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/31 08:34:21 by cmariot          ###   ########.fr       */
=======
/*   Updated: 2022/05/30 18:58:35 by rballage         ###   ########.fr       */
>>>>>>> 49a8b99c3cd1db679c63da8838eb7e7b48ed2df0
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_triangle_normale(t_ray *ray, t_obj *obj)
{
	t_v3	ab;
	t_v3	ac;

	ab = sub_lvalue(&obj->b, &obj->a);
	ac = sub_lvalue(&obj->c, &obj->a);
	ray->normale = normalize(cross_lvalue(&ab, &ac));
}

static bool	pts_lies_in_triangle(t_ray *ray, t_obj *obj)
{
	t_v3	c[3];
	t_v3	p;
	t_v3	norm_pbc;
	t_v3	norm_pca;
	t_v3	norm_pab;

	p = ray->intersection;
	c[0] = sub_lvalue(&obj->a, &p);
	c[1] = sub_lvalue(&obj->b, &p);
	c[2] = sub_lvalue(&obj->c, &p);
	norm_pbc = cross_lvalue(&c[1], &c[2]);
	norm_pca = cross_lvalue(&c[2], &c[0]);
	if (dot_lvalue(&norm_pbc, &norm_pca) < 0.0)
		return (false);
	norm_pab = cross_lvalue(&c[0], &c[1]);
	if (dot_lvalue(&norm_pbc, &norm_pab) < 0.0)
		return (false);
	return (true);
}

bool	intersection_triangle(t_obj *obj, t_ray *ray)
{
	double	d;

	get_triangle_normale(ray, obj);
	d = dot_lvalue(&ray->normale, &obj->a);
	if (!d)
		return (false);
	ray->t = (dot_lvalue(&ray->normale, &ray->position) + d)
		/ dot_lvalue(&ray->normale, &ray->direction);
	ray->normale = obj->direction;
	if (!obj->radius)
		return (false);
	ray->t = obj->radius / dot_lvalue(&obj->direction, &ray->direction);
	if (ray->t < 0)
		return (false);
	ray->intersection = multiply_lvalue(&ray->direction, ray->t);
	return (pts_lies_in_triangle(ray, obj));
}
