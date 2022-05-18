/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 21:46:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if defined __APPLE__
#  define ESC_KEY 53
#  define C_KEY 8
#  define L_KEY 37

# elif defined unix
#  define ESC_KEY 65307

# endif

#endif
