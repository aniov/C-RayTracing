/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtracer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:22:01 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:39:57 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ini_helper_var(t_helper *h, t_env *e, int x, int y)
{
	h->color.red = 0;
	h->color.green = 0;
	h->color.blue = 0;
	h->light = e->scene->light;
	h->coef = 1;
	h->t = 1e6;
	h->times = -1;
	h->lenght = 0;
	h->r.direction.x = e->scene->rayx;
	h->r.direction.y = e->scene->rayy;
	h->r.direction.z = e->scene->rayz;
	h->r.direction = vector_normalised(&h->r.direction);
	h->r.start.x = x;
	h->r.start.y = y;
	h->r.start.z = -1e3;
	h->obj.obj_name = 'x';
	h->obj.obj_nr = -1;
}

void	check_shadow_for_every_light(t_scene *scene, t_helper *h)
{
	int		i;
	double	temp;

	i = -1;
	while (++i < scene->light_nr)
	{
		h->dist = vector_sub(&h->light[i].position, &h->newstart);
		if (vector_dot(&h->n, &h->dist) <= 0.0f)
			continue;
		h->t = vector_lenght(&h->dist);
		h->lightray.start = h->newstart;
		h->lightray.direction = vector_scale((1 / h->t), &h->dist);
		h->light_proj = vector_dot(&h->lightray.direction, &h->n);
		if ((temp = vector_dot(&h->lightray.direction,
						&h->lightray.direction)) == 0.0f)
			continue;
		h->light_proj *= 1 / sqrtf(temp);
		if (!is_in_shadow(scene, h))
			calculate_color(h, scene, i);
	}
}

void	get_pixel_color(t_env *e, t_scene *scene, int x, int y)
{
	t_helper	h;
	int			i;

	ini_helper_var(&h, e, x, y);
	while (++h.times < 100)
	{
		i = -1;
		if (!(intersect_objects(scene, &h.r, &h)))
			break ;
		if (!get_normal_to_surface(&h.obj, &h, scene))
			break ;
		check_shadow_for_every_light(scene, &h);
		h.coef *= get_color_reflx(scene, &h.obj);
		h.r.start = h.newstart;
		h.reflect = 2.0000f * vector_dot(&h.r.direction, &h.n);
		h.tmp = vector_scale(h.reflect, &h.n);
		h.r.direction = vector_sub(&h.r.direction, &h.tmp);
	}
	set_color(&h, scene, e);
}

void	get_color(t_env *e)
{
	int			x;
	int			y;
	t_scene		*scene;

	scene = e->scene;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			get_pixel_color(e, scene, x, y);
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 2] = e->color.red;
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 1] = e->color.green;
			e->data[(y * e->size_line + (e->bpp / 8) * x) + 0] = e->color.blue;
			x++;
		}
		y++;
	}
}
