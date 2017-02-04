/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:08:45 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 20:56:34 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_one_ini(t_light *light, t_sphere *s)
{
	ini_scene_coord(&s[0].position, WIN_W / 2 + 300, WIN_H / 2 - 40, 20);
	ini_scene_coord(&s[1].position, 300.0, 500.0, 250.0);
	ini_scene_coord(&s[2].position, WIN_W / 2, WIN_H + 49780, 0.0);
	ini_scene_coord(&s[3].position, 280.0, 250.0, 0.0);
	s[0].radius = 230;
	s[1].radius = 150;
	s[2].radius = 50000;
	s[3].radius = 150;
	ini_scene_coord(&light[0].position, 1200, 200, 650);
	light[0].intensity = 1.0;
	ini_scene_coord(&light[1].position, 0, 0, -10);
	light[1].intensity = 1.0;
	ini_scene_coord(&light[2].position, 1800, 300, 1000);
	light[2].intensity = 0.8;
}

void	scene_one_ini_colors(t_sphere *s)
{
	ini_scene_colors(&s[0].colors, 1, 1, 1);
	s[0].colors.reflx = 0.9;
	s[0].material = 0.6;
	ini_scene_colors(&s[1].colors, 0.5, 0.9, 0.5);
	s[1].colors.reflx = 0.4;
	s[1].material = 1.2;
	ini_scene_colors(&s[2].colors, 1, 0.8, 0.75);
	s[2].colors.reflx = 0.7;
	s[2].material = 0.7;
	ini_scene_colors(&s[3].colors, 1.0, 0.1, 0.5);
	s[3].colors.reflx = 0.6;
	s[3].material = 0.7;
}

void	scene_one(t_scene *scene)
{
	sphere_creator(scene, 4);
	light_creator(scene, 3);
	scene_one_ini(scene->light, scene->sphere);
	scene_one_ini_colors(scene->sphere);
	scene->background.red = 0.0;
	scene->background.green = 0.0;
	scene->background.blue = 0.0;
}
