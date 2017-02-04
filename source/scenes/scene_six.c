/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:10:29 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:11:17 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_six_ini(t_light *light, t_sphere *s)
{
	int i;
	int j;

	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 5)
		{
			ini_scene_coord(&s[i * 5 + j].position,
					j * 180 + 220, i * 130 + 80, 0);
			s[i * 5 + j].radius = 60;
			ini_scene_colors(&s[i * 5 + j].colors, 0.7 - i * 0.12,
					i * 0.1 + j * 0.05, j * 0.12);
			s[i * 5 + j].colors.reflx = 0.9;
			s[i * 5 + j].material = 0.9;
		}
	}
	ini_scene_coord(&light[0].position, 1200, 200, 65);
	light[0].intensity = 1.4;
	ini_scene_coord(&light[1].position, WIN_W / 2, 400, -70);
	light[1].intensity = 1.5;
	ini_scene_coord(&light[2].position, 0, 800, -60);
	light[2].intensity = 1.4;
}

void	scene_six_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.0;
	scene->background.green = 0.0;
	scene->background.blue = 0.0;
}

void	scene_six_ini_colors(t_sphere *s)
{
	ini_scene_coord(&s[25].position, 600, WIN_H + 69890, 300);
	s[25].radius = 70000;
	ini_scene_colors(&s[25].colors, 0.9, 0.9, 0.9);
	s[25].colors.reflx = 0.9;
	s[25].material = 0.9;
}

void	scene_six(t_scene *scene)
{
	sphere_creator(scene, 26);
	light_creator(scene, 3);
	scene_six_ini(scene->light, scene->sphere);
	scene_six_ini_colors(scene->sphere);
	scene_six_ini_backgr(scene);
}
