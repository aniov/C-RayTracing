/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_angle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:15:39 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:53:58 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		set_angle_1(t_env *e, int keycode)
{
	e->obj_angle.x = 0;
	e->obj_angle.y = 0;
	e->obj_angle.z = 0;
	e->lights_angle.x = 0;
	e->lights_angle.y = 0;
	e->lights_angle.z = 0;
	if (keycode == OX_ROTATE_UP)
	{
		e->obj_angle.x = (!e->lights_lock ? RADIAN_ANGLE : e->obj_angle.x);
		e->lights_angle.x = RADIAN_ANGLE;
		return (1);
	}
	else if (keycode == OX_ROTATE_DOWN)
	{
		e->obj_angle.x = (!e->lights_lock ? -RADIAN_ANGLE : e->obj_angle.x);
		e->lights_angle.x = -RADIAN_ANGLE;
		return (1);
	}
	return (0);
}

void	set_angle(t_env *e, int keycode)
{
	if (set_angle_1(e, keycode))
		return ;
	else if (keycode == OY_ROTATE_UP)
	{
		e->obj_angle.y = (!e->lights_lock ? RADIAN_ANGLE : e->obj_angle.y);
		e->lights_angle.y = RADIAN_ANGLE;
	}
	else if (keycode == OY_ROTATE_DOWN)
	{
		e->obj_angle.y = (!e->lights_lock ? -RADIAN_ANGLE : e->obj_angle.y);
		e->lights_angle.y = -RADIAN_ANGLE;
	}
	else if (keycode == OZ_ROTATE_LEFT)
	{
		e->obj_angle.z = (!e->lights_lock ? RADIAN_ANGLE : e->obj_angle.z);
		e->lights_angle.z = RADIAN_ANGLE;
	}
	else if (keycode == OZ_ROTATE_RIGHT)
	{
		e->obj_angle.z = (!e->lights_lock ? -RADIAN_ANGLE : e->obj_angle.z);
		e->lights_angle.z = -RADIAN_ANGLE;
	}
}
