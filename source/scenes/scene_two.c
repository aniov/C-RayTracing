/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:12:41 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:53:05 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static void	scene_two_ini(t_light *light, t_plane *p, t_sphere *s)
{
	ini_scene_coord(&p[0].point, 0, 200, 70);
	ini_scene_coord(&p[0].point3, 200, 0, 70);
	p[0].normal = vector_cross(&p[0].point, &p[0].point3);
	p[0].normal = vector_normalised(&p[0].normal);
	ini_scene_coord(&s[0].position, WIN_W / 2 - 100, WIN_H / 2, 200);
	s[0].radius = 150;
	ini_scene_coord(&light[0].position, WIN_W / 2 - 400, 400, -400);
	light[0].intensity = 1.6;
}

static void	scene_two_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.2;
	scene->background.green = 0.7;
	scene->background.blue = 0.2;
}

static void	scene_two_ini_colors(t_plane *p, t_sphere *s)
{
	ini_scene_colors(&p[0].colors, 0.3, 0.3, 0.9);
	p[0].colors.reflx = 0.5;
	p[0].material = 0.5;
	ini_scene_colors(&s[0].colors, 1.0, 0.3, 0.6);
	s[0].colors.reflx = 0.2;
	s[0].material = 0.5;
}

void		scene_two(t_scene *scene)
{
	plane_creator(scene, 1);
	sphere_creator(scene, 1);
	light_creator(scene, 1);
	scene_two_ini(scene->light, scene->plane, scene->sphere);
	scene_two_ini_colors(scene->plane, scene->sphere);
	scene_two_ini_backgr(scene);
}
