/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:10:36 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:11:07 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_pos(t_light *light, double x, double y, double z)
{
	light->x = x;
	light->y = y;
	light->z = z;
}

void	sphere_pos(t_sphere *sphere, double x, double y, double z)
{
	sphere->x = x;
	sphere->y = y;
	sphere->z = z;
}

void	cylinder_pos(t_cylinder *cylinder, double x, double y, double z)
{
	cylinder->x = x;
	cylinder->y = y;
	cylinder->z = z;
}

void	cone_pos(t_cone *cone, double x, double y, double z)
{
	cone->x = x;
	cone->y = y;
	cone->z = z;
}

void	plane_pos(t_plane *plane, double x, double y, double z)
{
	sphere->x = x;
	sphere->y = y;
	sphere->z = z;
}
