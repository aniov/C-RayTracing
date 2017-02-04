/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:43:44 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:14:34 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	calc_denom(t_ray *r, t_sphere *s, double t[2])
{
	t_quad q;
	t_vect distance;

	distance = vector_sub(&r->start, &s->position);
	q.a = vector_dot(&r->direction, &r->direction);
	q.b = 2 * vector_dot(&r->direction, &distance);
	q.c = vector_dot(&distance, &distance) - s->radius * s->radius;
	if ((q.d = q.b * q.b - 4 * q.a * q.c) < 1e-3)
		return (0);
	t[0] = (-q.b - sqrtf(q.d)) / 2 * q.a;
	t[1] = (-q.b + sqrtf(q.d)) / 2 * q.a;
	return (1);
}

int			intersect_sphere(t_ray *r, t_sphere *s, int i, t_helper *h)
{
	double t[2];

	if (!calc_denom(r, s, t))
		return (0);
	if (t[0] > 1e-1 && t[0] < h->t)
	{
		h->t = t[0];
		h->obj.obj_name = 's';
		h->obj.obj_nr = i;
		return (1);
	}
	if (t[1] > 1e-1 && t[1] < h->t)
	{
		h->t = t[1];
		h->obj.obj_name = 's';
		h->obj.obj_nr = i;
		return (1);
	}
	return (0);
}

int			intersect_spheres_objects(t_ray *r, t_scene *scene, t_helper *h)
{
	int i;
	int sphere_num;

	i = 0;
	sphere_num = -1;
	while (i < scene->sphere_nr)
	{
		if (intersect_sphere(r, &scene->sphere[i], i, h))
			sphere_num = i;
		i++;
	}
	return (sphere_num);
}
