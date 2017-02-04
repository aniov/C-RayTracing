/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:11:30 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:12:27 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	scene_three_ini(t_light *light, t_sphere *s, t_cylinder *c, t_plane *p)
{
	ini_scene_coord(&s[0].position, WIN_W / 2 + 100, WIN_H / 2, 10);
	ini_scene_coord(&s[1].position, 300, 300, -150);
	ini_scene_coord(&s[2].position, WIN_W / 2 + 200, WIN_H / 2 - 300, 50);
	ini_scene_coord(&c[0].base, WIN_W / 2, 200, 120);
	ini_scene_coord(&c[0].dir, WIN_W / 2 + 100, 100, -20);
	c[0].dir = vector_normalised(&c[0].dir);
	ini_scene_coord(&p[0].point, 0, 200, 200);
	ini_scene_coord(&p[0].point3, 200, 0, 200);
	p[0].normal = vector_cross(&p[0].point, &p[0].point3);
	s[0].radius = 100;
	s[1].radius = 150;
	s[2].radius = 90;
	c[0].radius = 140;
	ini_scene_coord(&light[0].position, WIN_W / 2, WIN_W / 2 - 100, -500);
	light[0].intensity = 1.2;
	ini_scene_coord(&light[1].position, 0, 0, -350);
	light[1].intensity = 1.2;
	ini_scene_coord(&light[2].position, 1800, 300, 180);
	light[2].intensity = 0.4;
}

void	scene_three_ini_backgr(t_scene *scene)
{
	scene->background.red = 0.15;
	scene->background.green = 0.15;
	scene->background.blue = 0.15;
}

void	scene_three_ini_colors(t_sphere *s, t_cylinder *c, t_plane *p)
{
	ini_scene_colors(&s[0].colors, 0.2, 0.8, 0.2);
	s[0].colors.reflx = 0.9;
	s[0].material = 0.9;
	ini_scene_colors(&s[1].colors, 0.2, 0.2, 0.8);
	s[1].colors.reflx = 0.9;
	s[1].material = 1.2;
	ini_scene_colors(&s[2].colors, 1.0, 1.0, 0.0);
	s[2].colors.reflx = 0.6;
	s[2].material = 0.7;
	ini_scene_colors(&c[0].colors, 0.6, 0.1, 0.1);
	c[0].colors.reflx = 0.7;
	c[0].material = 0.8;
	ini_scene_colors(&p[0].colors, 0.7, 0.7, 0.7);
	p[0].colors.reflx = 0.1;
	p[0].material = 0.5;
}

void	scene_three(t_scene *scene)
{
	sphere_creator(scene, 3);
	cylinder_creator(scene, 1);
	plane_creator(scene, 1);
	light_creator(scene, 3);
	scene_three_ini(scene->light, scene->sphere,
			scene->cylinder, scene->plane);
	scene_three_ini_colors(scene->sphere, scene->cylinder, scene->plane);
	scene_three_ini_backgr(scene);
}
