/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_eight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:01:41 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:03:56 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_eight_ini(t_sphere *s)
{
	int i;

	i = -1;
	while (++i < 150)
	{
		ini_scene_coord(&s[i].position, 400, i * 2 + 200, 0);
		s[i].radius = 150;
		ini_scene_colors(&s[i].colors, 0.9, 0.3, 0.9);
		s[i].colors.reflx = 0.6;
		s[i].material = 0.9;
	}
	while (++i < 300)
	{
		ini_scene_coord(&s[i].position, 800, i * 2 - 100, 0);
		s[i].radius = 150;
		ini_scene_colors(&s[i].colors, 0.9, 0.9, 0.3);
		s[i].colors.reflx = 0.6;
		s[i].material = 0.9;
	}
}

void	scene_eight_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.0;
	scene->background.green = 0.0;
	scene->background.blue = 0.0;
}

void	scene_eight_ini_colors(t_light *light)
{
	ini_scene_coord(&light[0].position, 1200, 200, 65);
	light[0].intensity = 1.4;
	ini_scene_coord(&light[1].position, WIN_W / 2, 100, -200);
	light[1].intensity = 1.4;
	ini_scene_coord(&light[2].position, 100, 400, -100);
	light[2].intensity = 1.4;
}

void	scene_eight(t_scene *scene)
{
	sphere_creator(scene, 300);
	light_creator(scene, 3);
	scene_eight_ini(scene->sphere);
	scene_eight_ini_colors(scene->light);
	scene_eight_ini_backgr(scene);
}
