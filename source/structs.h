/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:44:46 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:30:56 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_mat
{
	double		x[3][3];
	double		y[3][3];
	double		z[3][3];
	double		r[3][3];
}				t_mat;

typedef struct	s_angle
{
	double		x;
	double		y;
	double		z;
}				t_angle;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_ray
{
	t_vect		start;
	t_vect		direction;
}				t_ray;

typedef struct	s_color
{
	double		red;
	double		green;
	double		blue;
	double		reflx;
}				t_color;

typedef struct	s_sphere
{
	t_vect		position;
	double		radius;
	t_color		colors;
	double		material;
}				t_sphere;

typedef struct	s_plane
{
	t_vect		point;
	t_vect		normal;
	t_vect		point3;
	t_color		colors;
	double		material;
}				t_plane;

typedef struct	s_light
{
	t_vect		position;
	double		radius;
	double		intensity;
}				t_light;

typedef struct	s_cylinder
{
	t_vect		base;
	t_vect		dir;
	double		radius;
	t_color		colors;
	double		material;
	double		height;
}				t_cylinder;

typedef struct	s_cone
{
	t_vect		center;
	t_vect		dir;
	double		radius;
	t_color		colors;
	double		material;
	double		height;
	double		sin_angle;
}				t_cone;

typedef struct	s_scene
{
	t_light		*light;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_cone		*cone;
	t_color		background;
	int			sphere_nr;
	int			cylinder_nr;
	int			cone_nr;
	int			plane_nr;
	int			light_nr;
	double		rayx;
	double		rayy;
	double		rayz;
}				t_scene;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	t_color		color;
	int			size_line;
	int			lights_lock;
	t_angle		lights_angle;
	t_angle		obj_angle;
	t_mat		mat;
	t_scene		*scene;
	int			endian;
}				t_env;

typedef struct	s_obj
{
	char		obj_name;
	int			obj_nr;
}				t_obj;

typedef struct	s_helper
{
	t_light		*light;
	t_sphere	*s;
	t_cylinder	*cy;
	t_cone		*co;
	t_plane		*p;
	t_ray		r;
	t_ray		lightray;
	t_vect		scaled;
	t_vect		newstart;
	t_vect		n;
	t_vect		dist;
	t_vect		tmp;
	t_color		color;
	t_obj		obj;
	double		t;
	double		lambert;
	double		coef;
	double		lenght;
	double		material;
	double		light_proj;
	double		view_proj;
	int			times;
	int			firstobj;
	double		reflect;
}				t_helper;

typedef struct	s_quad
{
	double		a;
	double		b;
	double		c;
	double		d;
}				t_quad;

#endif
