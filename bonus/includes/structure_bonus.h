/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:38:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/02 11:01:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_BONUS_H
# define STRUCTURE_BONUS_H

struct				s_obj;
struct				s_ray;

typedef void		(*t_m_print)(void *);
typedef bool		(*t_m_inter)(struct s_obj *, struct s_ray *);
typedef void		(*t_m_trans)(struct s_obj *, struct s_v3);

typedef enum e_bool {
	false_,
	true_
}	t_bool;

// Image MiniLibX
typedef struct s_img {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_img;

// Structure MiniLibX
typedef struct s_mlx {
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			image;
}	t_mlx;

typedef struct s_discriminant {
	double	abc[3];
	double	delta;
}	t_discriminant;

// Structure couleur RGB
typedef struct s_color {
	double			r;
	double			g;
	double			b;
	int				trgb;
}	t_color;

// Spot lumiere
typedef struct s_light {
	t_m_print		print;
	t_v3			position;
	double			ratio;
	t_color			color;
	bool			color_set;
}	t_light;

// Lumiere ambiante
typedef struct t_amb {
	t_m_print		print;
	t_color			color;
	double			ratio;
	double			ambient_constant;
}	t_amb;

// Rayon
typedef struct s_ray {
	t_v3			position;
	t_v3			direction;
	double			t;
	t_v3			intersection;
	t_v3			normale;
}	t_ray;

// Camera
typedef struct s_cam {
	t_m_print		print;
	t_v3			position;
	t_v3			direction;
	double			matrix[9];
	t_ray			ray;
	double			screen_width;
	double			screen_height;
	double			fov_horizontal;
	double			constant_x;
	double			constant_y;
	double			constant_z;
}	t_cam;

// Structure utilisée pour les sphere, cylindres et plans
// Pointeurs sur fonction (type commencant par 't_m_') = methodes
typedef struct s_obj {
	t_m_inter		intersection;
	t_m_inter		second_intersection;
	t_m_trans		translate;
	t_m_print		print;
	t_v3			position;
	t_v3			direction;
	t_color			color;
	double			radius;
	double			height;
	double			demi_height;
	t_v3			ext1;
	t_v3			ext2;
	t_v3			axe;
	t_v3			a;
	t_v3			b;
	t_v3			c;
}	t_obj;

// Liste des objets
typedef struct s_obj_list {
	size_t			nb_obj;
	size_t			nb_camera;
	size_t			nb_ambient;
	size_t			nb_light;
	t_obj			*obj;
	t_cam			camera;
	t_amb			ambient;
	t_light			*light;
}	t_obj_list;

// Structure principale
typedef struct s_world {
	t_obj_list		obj_list;
	t_mlx			mlx;
}	t_world;

#endif
