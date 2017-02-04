/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:47:29 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:32:02 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "key_def.h"
# include "structs.h"

# define WIN_W 1200
# define WIN_H 800

void	key_move(t_env *e, int keycode);
int		expose_hook(t_env *e);
void	create_window(t_env *e);
int		key_hook(int keycode, t_env *e);
void	draw_image(t_env *e);
t_vect	vector_add(t_vect *v1, t_vect *v2);
t_vect	vector_sub(t_vect *v1, t_vect *v2);
double	vector_dot(t_vect *v1, t_vect *v2);
t_vect	vector_scale(double nr, t_vect *v);
t_vect	vector_cross(t_vect *v1, t_vect *v2);
t_vect	vector_normalised(t_vect *vect);
double	vector_lenght(t_vect *v);
int		intersect_sphere(t_ray *r, t_sphere *s, int i, t_helper *h);
int		intersect_cylinder(t_ray *r, t_cylinder *cy, int i, t_helper *h);
int		intersect_cone(t_ray *r, t_cone *co, int i, t_helper *h);
int		intersect_plane(t_ray *r, t_plane *p, int i, t_helper *h);
void	scene_one(t_scene *scene);
void	scene_two(t_scene *scene);
void	scene_three(t_scene *scene);
void	scene_four(t_scene *scene);
void	scene_five(t_scene *scene);
void	scene_six(t_scene *scene);
void	scene_seven(t_scene *scene);
void	scene_eight(t_scene *scene);
void	scene_nine(t_scene *scene);
void	ini_scene_colors(t_color *color, double red, double green, double blue);
void	ini_scene_coord(t_vect *position, double x, double y, double z);
int		intersect_objects(t_scene *scene, t_ray *r, t_helper *h);
int		intersect_spheres_objects(t_ray *r, t_scene *scene, t_helper *h);
int		intersect_cylinders_objects(t_ray *r, t_scene *scene, t_helper *h);
int		intersect_cones_objects(t_ray *r, t_scene *scene, t_helper *h);
int		intersect_planes_objects(t_ray *r, t_scene *scene, t_helper *h);
t_vect	get_normal_to_cylinder(t_scene *scene, t_obj *obj, t_helper *h);
t_vect	get_normal_to_cone(t_scene *scene, t_obj *obj, t_helper *h);
int		is_in_shadow(t_scene *scene, t_helper *h);
void	calculate_color(t_helper *h, t_scene *scene, int i);
void	set_color(t_helper *h, t_scene *scene, t_env *e);
void	sphere_creator(t_scene *scene, int sphere_nr);
void	cylinder_creator(t_scene *scene, int cylinder_nr);
void	cone_creator(t_scene *scene, int cone_nr);
void	plane_creator(t_scene *scene, int plane_nr);
void	light_creator(t_scene *scene, int lights_nr);
void	concatenate_matrices(t_env *e, double x, double y, double z);
void	helper_matrix_ini(t_env *e, double x, double y, double z);
void	multiply_matrix(double first_mat[3][3], double scnd_mat[3][3],
		double result_mat[3][3]);
void	make_the_math(t_env *e, t_scene *scene, int obj_nr);
void	rotate(t_env *e, t_scene *scene);
void	move(t_env *e, int keycode);
void	change_lights_intensity(t_scene *scene, int keycode);
void	set_angle(t_env *e, int keycode);
int		get_normal_to_surface(t_obj *obj, t_helper *h, t_scene *scene);
void	get_color(t_env *e);
double	get_color_reflx(t_scene *scene, t_obj *obj);

#endif
