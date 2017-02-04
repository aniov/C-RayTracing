/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_nine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:07:44 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 21:33:13 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_nine_ini(t_light *light, t_sphere *s)
{
	int i;

	i = -1;
	while (++i < 800)
	{
		ini_scene_coord(&s[i].position, 400,
				(i % 2 == 0 ? 400 + i : 400 - i), 0);
		s[i].radius = i * 0.5 + 1;
		ini_scene_colors(&s[i].colors, 0.9, 0.3, 0.8);
		s[i].colors.reflx = 0.4;
		s[i].material = 0.9;
	}
	ini_scene_coord(&light[0].position, 1200, 200, -300);
	light[0].intensity = 1.4;
	ini_scene_coord(&light[1].position, WIN_W / 2, 200, -90);
	light[1].intensity = 1.5;
	ini_scene_coord(&light[2].position, 0, 0, -10);
	light[2].intensity = 1.4;
}

void	scene_nine_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.2;
	scene->background.green = 0.3;
	scene->background.blue = 0.6;
}

void	scene_nine_ini_colors(t_sphere *s)
{
	ini_scene_coord(&s[800].position, 600, 400, 30);
	s[800].radius = 160;
	ini_scene_colors(&s[800].colors, 0.3, 0.8, 0.4);
	s[800].colors.reflx = 0.9;
	s[800].material = 0.9;
	ini_scene_coord(&s[801].position, 200, 400, 30);
	s[801].radius = 160;
	ini_scene_colors(&s[801].colors, 0.3, 0.4, 0.8);
	s[801].colors.reflx = 0.9;
	s[801].material = 0.9;
	ini_scene_coord(&s[802].position, 600, WIN_H + 49950, 0);
	s[802].radius = 50000;
	ini_scene_colors(&s[802].colors, 0.2, 0.1, 0.1);
	s[802].colors.reflx = 0.1;
	s[802].material = 0.1;
	ini_scene_coord(&s[803].position, 855, 210, 30);
	s[803].radius = 160;
	ini_scene_colors(&s[803].colors, 0.3, 0.4, 0.8);
	s[803].colors.reflx = 0.9;
	s[803].material = 0.9;
	ini_scene_coord(&s[804].position, 855, 590, 30);
	s[804].radius = 160;
	ini_scene_colors(&s[804].colors, 0.9, 0.99, 0.3);
	s[804].colors.reflx = 0.9;
	s[804].material = 0.9;
}

void	scene_nine(t_scene *scene)
{
	sphere_creator(scene, 805);
	light_creator(scene, 3);
	scene_nine_ini(scene->light, scene->sphere);
	scene_nine_ini_colors(scene->sphere);
	scene_nine_ini_backgr(scene);
}
