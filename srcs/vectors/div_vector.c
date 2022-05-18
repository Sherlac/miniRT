/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 01:42:12 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 11:01:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern inline t_v3	div_vector(t_v3 a, double b)
{
	return (new_vector(a.x / b, a.y / b, a.z / b));
}
