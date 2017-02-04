/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:04:11 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:05:35 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_five_ini(t_light *light, t_cone *co, t_sphere *s)
{
	ini_scene_coord(&co[0].center, WIN_W / 2, 300, 0);
	ini_scene_coord(&co[0].dir, WIN_W / 2 + 100, 300, 0);
	co[0].dir = vector_sub(&co[0].center, &co[0].dir);
	co[0].dir = vector_normalised(&co[0].dir);
	ini_scene_coord(&s[0].position, WIN_W / 2 + 300, 600, 80);
	ini_scene_coord(&s[1].position, WIN_W / 2 - 200, 300, -50);
	ini_scene_coord(&light[0].position, 120, 0, 100);
	light[0].intensity = 1.9;
	ini_scene_coord(&light[1].position, 1300, 600, -3700);
	light[1].intensity = 1.9;
	ini_scene_coord(&light[2].position, 0, 0, -200);
	light[2].intensity = 1.9;
	co[0].radius = 60;
	co[0].sin_angle = 0.3;
	s[0].radius = 130;
	s[1].radius = 180;
}

void	scene_five_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.05;
	scene->background.green = 0.05;
	scene->background.blue = 0.05;
}

void	scene_five_ini_colors(t_cone *co, t_sphere *s)
{
	ini_scene_colors(&co[0].colors, 0.2, 0.3, 0.9);
	co[0].colors.reflx = 0.6;
	co[0].material = 0.7;
	ini_scene_colors(&s[1].colors, 0.2, 0.9, 0.2);
	s[1].colors.reflx = 0.6;
	s[1].material = 0.8;
	ini_scene_colors(&s[0].colors, 0.6, 0.2, 0.2);
	s[0].colors.reflx = 0.8;
	s[0].material = 0.8;
}

void	scene_five(t_scene *scene)
{
	cone_creator(scene, 1);
	sphere_creator(scene, 2);
	light_creator(scene, 3);
	scene_five_ini(scene->light, scene->cone, scene->sphere);
	scene_five_ini_colors(scene->cone, scene->sphere);
	scene_five_ini_backgr(scene);
}
