/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_ini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:33:29 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:34:38 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ini_scene_coord(t_vect *position, double x, double y, double z)
{
	position->x = x;
	position->y = y;
	position->z = z;
}

void	ini_scene_colors(t_color *color, double red, double green, double blue)
{
	color->red = red;
	color->green = green;
	color->blue = blue;
}
