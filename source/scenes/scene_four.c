/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:05:52 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:07:27 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static void	scene_four_ini(t_light *light, t_plane *p, t_sphere *s)
{
	ini_scene_coord(&p[0].point, 0, 200, 70);
	ini_scene_coord(&p[0].point3, 200, 0, 70);
	p[0].normal = vector_cross(&p[0].point, &p[0].point3);
	p[0].normal = vector_normalised(&p[0].normal);
	ini_scene_coord(&p[1].point, 600, 200, 90);
	ini_scene_coord(&p[1].point3, 0, 50, 90);
	p[1].normal = vector_cross(&p[1].point3, &p[1].point);
	p[1].normal = vector_normalised(&p[1].normal);
	ini_scene_coord(&s[0].position, WIN_W / 2 - 100, WIN_H / 2, 200);
	s[0].radius = 150;
	ini_scene_coord(&light[0].position, WIN_W / 2 - 400, 400, -400);
	light[0].intensity = 1.1;
	ini_scene_coord(&light[1].position, 900, 500, -100);
	light[1].intensity = 1.1;
}

static void	scene_four_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.2;
	scene->background.green = 0.7;
	scene->background.blue = 0.2;
}

static void	scene_four_ini_colors(t_plane *p, t_sphere *s)
{
	ini_scene_colors(&p[0].colors, 0.3, 0.3, 0.9);
	p[0].colors.reflx = 0.2;
	p[0].material = 0.5;
	ini_scene_colors(&p[1].colors, 0.4, 0.9, 0.4);
	p[1].colors.reflx = 0.2;
	p[1].material = 0.5;
	ini_scene_colors(&s[0].colors, 0.6, 0.6, 0.6);
	s[0].colors.reflx = 0.0;
	s[0].material = 0.3;
}

void		scene_four(t_scene *scene)
{
	plane_creator(scene, 2);
	sphere_creator(scene, 1);
	light_creator(scene, 2);
	scene_four_ini(scene->light, scene->plane, scene->sphere);
	scene_four_ini_colors(scene->plane, scene->sphere);
	scene_four_ini_backgr(scene);
}
