/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:04:09 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:33:32 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		intersect_objects(t_scene *scene, t_ray *r, t_helper *h)
{
	int sphere_ind;
	int cyl_ind;
	int cone_ind;
	int plane_ind;

	sphere_ind = intersect_spheres_objects(r, scene, h);
	cyl_ind = intersect_cylinders_objects(r, scene, h);
	cone_ind = intersect_cones_objects(r, scene, h);
	plane_ind = intersect_planes_objects(r, scene, h);
	if (sphere_ind != -1 || cyl_ind != -1 || cone_ind != -1 || plane_ind != -1)
	{
		return (1);
	}
	return (0);
}

int		get_normal_to_surface(t_obj *obj, t_helper *h, t_scene *scene)
{
	h->scaled = vector_scale(h->t, &h->r.direction);
	h->newstart = vector_add(&h->r.start, &h->scaled);
	if (obj->obj_name == 's')
	{
		h->n = vector_sub(&h->newstart, &scene->sphere[obj->obj_nr].position);
		h->material = scene->sphere[obj->obj_nr].material;
	}
	else if (obj->obj_name == 'c')
		h->n = get_normal_to_cylinder(scene, obj, h);
	else if (obj->obj_name == 'k')
		h->n = get_normal_to_cone(scene, obj, h);
	else if (obj->obj_name == 'p')
	{
		h->n = scene->plane[obj->obj_nr].normal;
		h->material = scene->plane[obj->obj_nr].material;
	}
	if ((h->lenght = vector_dot(&h->n, &h->n)) == 0.000f)
		return (0);
	h->n = vector_scale(1.000f / sqrtf(h->lenght), &h->n);
	return (1);
}

t_vect	get_normal_to_cone(t_scene *scene, t_obj *obj, t_helper *h)
{
	t_vect a;
	t_vect b;
	t_vect c;
	t_vect d;

	a = vector_sub(&h->newstart, &scene->cone[obj->obj_nr].center);
	b = vector_cross(&scene->cone[obj->obj_nr].dir, &a);
	c = vector_sub(&scene->cone[obj->obj_nr].center, &h->newstart);
	d = vector_cross(&c, &b);
	h->material = scene->cone[obj->obj_nr].material;
	return (vector_normalised(&d));
}

t_vect	get_normal_to_cylinder(t_scene *scene, t_obj *obj, t_helper *h)
{
	t_vect a;
	t_vect b;
	t_vect c;

	a = vector_sub(&h->newstart, &scene->cylinder[obj->obj_nr].base);
	b = vector_cross(&scene->cylinder[obj->obj_nr].dir, &a);
	c = vector_cross(&scene->cylinder[obj->obj_nr].dir, &b);
	h->material = scene->cylinder[obj->obj_nr].material;
	return (vector_normalised(&c));
}
