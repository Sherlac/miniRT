/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:30:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 12:59:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_v3	get_normale(t_ray *ray, t_obj *sphere)
{
	t_v3	origine;
	t_v3	normale1;
	t_v3	normale2;

	origine = sub_vector(ray->position, ray->intersection);
	normale1 = normalize(sub_vector(ray->intersection, sphere->position));
	normale2 = mul_vector(normale1, -1);
	if (norm_square(sub_vector(origine, normale1))
		< norm_square(sub_vector(origine, normale2)))
		return (normale1);
	else
		return (normale2);
}

/*
 * SYSTEME D'ÉQUATION PARAMETRIQUES DU RAYON :
 *  x(t) -> ray->direction.x * t + ray->position.x
 *  y(t) -> ray->direction.y * t + ray->position.y
 *  z(t) -> ray->direction.z * t + ray->position.z
 *
 * EQUATION SPHERE : UN POINT EST SUR LA SPHERE SI IL Y A UNE SOLUTION
 *   x^2 + y^2 + z^2 = (sphere.radius)^2
 *
 * EN REMPLACANT LES ELEMENTS DANS L'EQUATION SPHERE :
 *   (ray->direction.x * t + ray->position.x)^2
 * + (ray->direction.y * t + ray->position.y)^2
 * + (ray->direction.z * t + ray->position.z)^2 - (sphere.radius)^2 = 0
 *
 * ON DEVELOPPE AVEC LES IDENTITES REMARQUABLES (A+B)^2 = A^2 + 2AB + B^2
 * (ray->direction.x * t)^2 + (ray->direction.y * t)^2 + (ray->direction.z * t)^2
 * + 2(ray->direction.x * t * ray->position.x)
 * + 2(ray->direction.y * t * ray->position.y)
 * + 2(ray->direction.z * t * ray->position.z)
 * + ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 * - (sphere.radius)^2 = 0
 *
 * REFORMULATION SOUS LA FORME At^2 + Bt + C = 0:
 *   ((ray->direction.x)^2 + (ray->direction.y)^2 + (ray->direction.z)^2) * t^2
 * + ((ray->direction.x * ray->position.x)
 * + (ray->direction.y * ray->position.y)
 * + (ray->direction.z * ray->position.z) * 2 * t)
 * + ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 * - (sphere.radius)^2 = 0
 *
 * ON DETERMINE A B ET C DU DISCRIMINANT 
 * A = ((ray->direction.x)^2 + (ray->direction.y)^2 + (ray->direction.z)^2)
 * B = ((ray->direction.x * ray->position.x)
 *     + (ray->direction.y * ray->position.y)
 *     + (ray->direction.z * ray->position.z)) * 2
 * C = ray->position.x^2 + ray->position.y^2 + ray->position.z^2
 *     - (sphere.radius)^2
 *
 * DELTA = B^2 - 4AC
 */

static double	get_solution(t_ray *ray, t_obj *sphere)
{
	t_v3		origin;
	double		abc[3];
	double		delta;

	origin = sub_vector(ray->position, sphere->position);
	abc[0] = norm_square(ray->direction);
	abc[1] = scalar_product(ray->direction, origin) * 2.0;
	abc[2] = norm_square(origin) - pow(sphere->radius, 2);
	delta = pow(abc[1], 2) - (4.0 * abc[0] * abc[2]);
	if (delta < 0)
		return (-1.0);
	else if (delta == 0)
		return (t1(delta, abc));
	else
		return (min_positive(t1(delta, abc), t2(delta, abc)));
}

/*
 * On a un rayon caracterisé par son point d'origine (position camera)
 * et sa direction (normalisée).
 * - origine : ray->position.x, ray->position.y, ray->position.z
 * - direction : ray->direction.x, ray->direction.y, ray->direction.z
 *
 * On cherche a trouver si ce rayon va toucher une sphere,
 * dont on connait la position du centre et le rayon.
 * - origine : sphere->position.x, sphere->position.y, sphere->position.z
 * - rayon : sphere->radius
 */

//Vecteur(x) =  direction * x + t
bool	intersection_sphere(t_obj *sphere, t_ray *ray)
{
	ray->t = get_solution(ray, sphere);
	if (ray->t < 0)
		return (false);
	ray->intersection = get_position(ray->position, ray->direction, ray->t);
	ray->normale = get_normale(ray, sphere);
	return (true);
}
