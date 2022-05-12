/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:26:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/01 01:39:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//#define ESC_KEY 53		// MacOS
#define ESC_KEY 65307	// Ubuntu

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
		close_window(scene);
	return (0);
}
