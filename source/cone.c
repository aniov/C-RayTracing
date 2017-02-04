/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:32:09 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 17:47:43 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	calc_denom(t_ray *r, t_cone *con, double t[2])
{
	t_quad q;
	t_vect unit_d;
	t_vect suport;
	double len_suport;
	double len_ray_d;

	suport = vector_sub(&r->start, &con->center);
	len_suport = sqrtf(vector_dot(&suport, &suport));
	unit_d = vector_sub(&con->center, &con->dir);
	unit_d = vector_normalised(&unit_d);
	len_ray_d = sqrtf(vector_dot(&r->direction, &r->direction));
	q.a = pow(len_ray_d, 2) - pow(vector_dot(&r->direction, &unit_d), 2)
		- pow(con->sin_angle, 2) * pow(len_ray_d, 2);
	q.b = 2 * vector_dot(&r->direction, &suport)
		- 2 * vector_dot(&r->direction, &unit_d) * vector_dot(&suport, &unit_d)
		- 2 * pow(con->sin_angle, 2) * vector_dot(&suport, &r->direction);
	q.c = pow(len_suport, 2) - pow(vector_dot(&suport, &unit_d), 2) -
		pow(con->sin_angle, 2) * pow(len_suport, 2);
	if ((q.d = q.b * q.b - 4.0 * q.a * q.c) < 1e-3)
		return (0);
	t[0] = (-q.b - sqrtf(q.d)) / 2.0 * q.a;
	t[1] = (-q.b + sqrtf(q.d)) / 2.0 * q.a;
	return (1);
}

int			intersect_cone(t_ray *r, t_cone *con, int i, t_helper *h)
{
	double t[2];

	if (!calc_denom(r, con, t))
		return (0);
	if (t[0] > 1e-1 && t[0] < h->t)
	{
		h->t = t[0];
		h->obj.obj_name = 'k';
		h->obj.obj_nr = i;
		return (1);
	}
	if (t[1] > 1e-1 && t[1] < h->t)
	{
		h->t = t[1];
		h->obj.obj_name = 'k';
		h->obj.obj_nr = i;
		return (1);
	}
	return (0);
}

int			intersect_cones_objects(t_ray *r, t_scene *scene, t_helper *h)
{
	int i;
	int cone_num;

	i = 0;
	cone_num = -1;
	while (i < scene->cone_nr)
	{
		if (intersect_cone(r, &scene->cone[i], i, h))
			cone_num = i;
		i++;
	}
	return (cone_num);
}
