/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:06:23 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:40:17 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			is_in_shadow(t_scene *scene, t_helper *h)
{
	char	tmp_obj_name;
	int		tmp_obj_nr;
	int		flag;

	tmp_obj_name = h->obj.obj_name;
	tmp_obj_nr = h->obj.obj_nr;
	flag = intersect_objects(scene, &h->lightray, h);
	h->obj.obj_name = tmp_obj_name;
	h->obj.obj_nr = tmp_obj_nr;
	return (flag);
}

static void	get_obj_color(t_helper *h, t_scene *scene, t_color *color,
		double *material)
{
	int ind;

	ind = h->obj.obj_nr;
	if (h->obj.obj_name == 's')
	{
		*color = scene->sphere[ind].colors;
		*material = scene->sphere[ind].material;
	}
	else if (h->obj.obj_name == 'c')
	{
		*color = scene->cylinder[ind].colors;
		*material = scene->cylinder[ind].material;
	}
	else if (h->obj.obj_name == 'k')
	{
		*color = scene->cone[ind].colors;
		*material = scene->cone[ind].material;
	}
	else if (h->obj.obj_name == 'p')
	{
		*color = scene->plane[ind].colors;
		*material = scene->plane[ind].material;
	}
}

void		calculate_color(t_helper *h, t_scene *scene, int i)
{
	double	material;
	double	temp;
	double	phong;
	t_color	color;
	t_vect	phong_dir;

	get_obj_color(h, scene, &color, &material);
	h->lambert = vector_dot(&h->lightray.direction, &h->n) * h->coef;
	h->color.red += h->lambert * color.red * h->light[i].intensity * material;
	h->color.green += h->lambert * color.green * h->light[i].intensity
		* material;
	h->color.blue += h->lambert * color.blue * h->light[i].intensity * material;
	h->view_proj = vector_dot(&h->r.direction, &h->n);
	phong_dir = vector_sub(&h->lightray.direction, &h->r.direction);
	temp = vector_dot(&phong_dir, &phong_dir);
	if (temp != 0.0f)
	{
		phong = (1 / sqrtf(temp) * ft_max_nr(h->light_proj
				- h->view_proj, 0.0f));
		phong = h->coef * powf(phong, 400);
		h->color.red += phong;
		h->color.green += phong;
		h->color.blue += phong;
	}
}

void		set_color(t_helper *h, t_scene *scene, t_env *e)
{
	if (h->times == 0)
	{
		h->color.red = scene->background.red;
		h->color.green = scene->background.green;
		h->color.blue = scene->background.blue;
	}
	e->color.red = ft_min_nr(h->color.red * 255, 255);
	e->color.green = ft_min_nr(h->color.green * 255, 255);
	e->color.blue = ft_min_nr(h->color.blue * 255, 255);
}

double		get_color_reflx(t_scene *scene, t_obj *obj)
{
	if (obj->obj_name == 's')
		return (scene->sphere[obj->obj_nr].colors.reflx);
	else if (obj->obj_name == 'c')
		return (scene->cylinder[obj->obj_nr].colors.reflx);
	else if (obj->obj_name == 'k')
		return (scene->cone[obj->obj_nr].colors.reflx);
	else if (obj->obj_name == 'p')
		return (scene->plane[obj->obj_nr].colors.reflx);
	return (0.0);
}
