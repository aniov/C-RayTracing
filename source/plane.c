/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:11:30 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:43:36 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	intersect_plane(t_ray *r, t_plane *p, int i, t_helper *h)
{
	double b;
	double d;
	double tt;

	if ((d = vector_dot(&r->direction, &p->normal)) == 0.0f)
		return (0);
	if ((b = vector_dot(&r->start, &p->normal)) >= 1e-3)
	{
		tt = -b / d;
		if (tt < h->t && tt >= 0)
		{
			h->obj.obj_name = 'p';
			h->obj.obj_nr = i;
			h->t = -b / d;
			return (1);
		}
	}
	return (0);
}

int	intersect_planes_objects(t_ray *r, t_scene *scene, t_helper *h)
{
	int i;
	int plane_num;

	i = 0;
	plane_num = -1;
	while (i < scene->plane_nr)
	{
		if (intersect_plane(r, &scene->plane[i], i, h))
			plane_num = i;
		i++;
	}
	return (plane_num);
}
