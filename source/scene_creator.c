/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:32:14 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:33:08 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sphere_creator(t_scene *scene, int sphere_nr)
{
	t_sphere *s;

	s = (t_sphere*)malloc(sizeof(t_sphere) * sphere_nr);
	scene->sphere = s;
	scene->sphere_nr = sphere_nr;
}

void	cylinder_creator(t_scene *scene, int cylinder_nr)
{
	t_cylinder *cy;

	cy = (t_cylinder*)malloc(sizeof(t_cylinder) * cylinder_nr);
	scene->cylinder = cy;
	scene->cylinder_nr = cylinder_nr;
}

void	cone_creator(t_scene *scene, int cone_nr)
{
	t_cone *co;

	co = (t_cone*)malloc(sizeof(t_cone) * cone_nr);
	scene->cone = co;
	scene->cone_nr = cone_nr;
}

void	light_creator(t_scene *scene, int lights_nr)
{
	t_light *light;

	light = (t_light*)malloc(sizeof(t_light) * lights_nr);
	scene->light = light;
	scene->light_nr = lights_nr;
}

void	plane_creator(t_scene *scene, int plane_nr)
{
	t_plane *p;

	p = (t_plane*)malloc(sizeof(t_plane) * plane_nr);
	scene->plane = p;
	scene->plane_nr = plane_nr;
}
