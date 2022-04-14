/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 01:25:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:35:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_plan(char **array, size_t *index, t_plan *plan)
{
	if (ft_arraylen(array) != 4)
	{
		ft_free_array(array);
		return (rt_error("Syntax error : Plan number of arguments.", true));
	}
	if (set_point(&(plan->center), array[1]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_orientation(&(plan->orientation), array[2]))
	{
		ft_free_array(array);
		return (1);
	}
	if (set_colors(array[3], &(plan->color)))
	{
		ft_free_array(array);
		return (1);
	}
	ft_free_array(array);
	*index = *index + 1;
	return (0);
}