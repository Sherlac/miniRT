/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:42:49 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 21:24:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

# define X 0
# define Y 1

void	mlx_putpixel(t_img *data, size_t *pixel, int color)
{
	char	*dst;

	dst = data->addr + (pixel[Y] * data->line_length
			+ pixel[X] * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
