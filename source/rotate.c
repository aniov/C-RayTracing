/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:05:38 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:21:38 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	move(t_env *e, int keycode)
{
	if (keycode == MOVE_UP_1)
		e->scene->rayy += 0.02;
	else if (keycode == MOVE_DOWN_1)
		e->scene->rayy -= 0.02;
	else if (keycode == MOVE_LEFT_1)
		e->scene->rayx += 0.02;
	else if (keycode == MOVE_RIGHT_1)
		e->scene->rayx -= 0.02;
	else if (keycode == Z_IN_2)
		e->scene->rayz += 0.02;
	else if (keycode == Z_OUT_2)
		e->scene->rayz -= 0.02;
}

void	concatenate_matrices(t_env *e, double anglex, double angley,
							double anglez)
{
	double temp[3][3];

	helper_matrix_ini(e, anglex, angley, anglez);
	multiply_matrix(e->mat.x, e->mat.y, temp);
	multiply_matrix(temp, e->mat.z, e->mat.r);
}

void	make_the_math_sphere(t_env *e, t_scene *scene, int obj_nr)
{
	double xyz[3];
	double nx;
	double ny;
	double nz;

	xyz[0] = scene->sphere[obj_nr].position.x - WIN_W / 2;
	xyz[1] = scene->sphere[obj_nr].position.y - WIN_H / 2;
	xyz[2] = scene->sphere[obj_nr].position.z;
	nx = e->mat.r[0][0] * xyz[0] + e->mat.r[0][1] * xyz[1] + e->mat.r[0][2]
		* xyz[2];
	ny = e->mat.r[1][0] * xyz[0] + e->mat.r[1][1] * xyz[1] + e->mat.r[1][2]
		* xyz[2];
	nz = e->mat.r[2][0] * xyz[0] + e->mat.r[2][1] * xyz[1] + e->mat.r[2][2]
		* xyz[2];
	scene->sphere[obj_nr].position.x = nx + WIN_W / 2;
	scene->sphere[obj_nr].position.y = ny + WIN_H / 2;
	scene->sphere[obj_nr].position.z = nz;
}

void	make_the_math_lights(t_env *e, t_scene *scene, int obj_nr)
{
	double xyz[3];
	double nx;
	double ny;
	double nz;

	xyz[0] = scene->light[obj_nr].position.x - WIN_W / 2;
	xyz[1] = scene->light[obj_nr].position.y - WIN_H / 2;
	xyz[2] = scene->light[obj_nr].position.z;
	nx = e->mat.r[0][0] * xyz[0] + e->mat.r[0][1] * xyz[1] + e->mat.r[0][2]
		* xyz[2];
	ny = e->mat.r[1][0] * xyz[0] + e->mat.r[1][1] * xyz[1] + e->mat.r[1][2]
		* xyz[2];
	nz = e->mat.r[2][0] * xyz[0] + e->mat.r[2][1] * xyz[1] + e->mat.r[2][2]
		* xyz[2];
	scene->light[obj_nr].position.x = nx + WIN_W / 2;
	scene->light[obj_nr].position.y = ny + WIN_H / 2;
	scene->light[obj_nr].position.z = nz;
}

void	rotate(t_env *e, t_scene *scene)
{
	int i;
	int obj_nr;

	obj_nr = ft_max_nr(scene->sphere_nr, scene->light_nr);
	obj_nr = ft_max_nr(obj_nr, scene->cylinder_nr);
	obj_nr = ft_max_nr(obj_nr, scene->cone_nr);
	i = 0;
	while (i < obj_nr)
	{
		concatenate_matrices(e, e->obj_angle.x, e->obj_angle.y, e->obj_angle.z);
		if (scene->sphere_nr > i)
			make_the_math_sphere(e, scene, i);
		if (scene->light_nr > i && e->lights_lock)
		{
			concatenate_matrices(e, e->lights_angle.x, e->lights_angle.y,
								e->lights_angle.z);
			make_the_math_lights(e, scene, i);
		}
		i++;
	}
}
