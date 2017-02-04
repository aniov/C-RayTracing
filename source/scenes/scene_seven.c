/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_seven.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:09:22 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:10:17 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_seven_ini(t_sphere *s)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			while (++k < 3)
			{
				ini_scene_coord(&s[i * 9 + j * 3 + k].position,
						j * 230 + 350, i * 230 + 180, k * 230);
				s[i * 9 + j * 3 + k].radius = 80;
				ini_scene_colors(&s[i * 9 + j * 3 + k].colors,
						0.9 - j * 0.1, 0.3 + j * 0.1, 0.3 + k * 0.1);
				s[i * 9 + j * 3 + k].colors.reflx = 0.9;
				s[i * 9 + j * 3 + k].material = 0.9;
			}
		}
	}
}

void	scene_seven_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.0;
	scene->background.green = 0.0;
	scene->background.blue = 0.0;
}

void	scene_seven_ini_colors(t_light *light)
{
	ini_scene_coord(&light[0].position, 1200, 200, -65);
	light[0].intensity = 1.4;
	ini_scene_coord(&light[1].position, 1200, 400, -70);
	light[1].intensity = 1.5;
	ini_scene_coord(&light[2].position, 0, 800, -60);
	light[2].intensity = 1.4;
}

void	scene_seven(t_scene *scene)
{
	sphere_creator(scene, 27);
	light_creator(scene, 3);
	scene_seven_ini(scene->sphere);
	scene_seven_ini_colors(scene->light);
	scene_seven_ini_backgr(scene);
}
