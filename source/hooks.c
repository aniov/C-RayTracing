/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 17:51:26 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:03:47 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	key_move(e, keycode);
	return (0);
}

void	draw_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &e->endian);
	get_color(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int		expose_hook(t_env *e)
{
	draw_image(e);
	return (0);
}

void	key_move(t_env *e, int keycode)
{
	if (keycode == OX_ROTATE_UP || keycode == OX_ROTATE_DOWN ||
			keycode == OY_ROTATE_UP || keycode == OY_ROTATE_DOWN ||
			keycode == OZ_ROTATE_LEFT || keycode == OZ_ROTATE_RIGHT)
	{
		set_angle(e, keycode);
		rotate(e, e->scene);
		draw_image(e);
	}
	else if (keycode == MOVE_UP_1 || keycode == MOVE_DOWN_1 ||
			keycode == MOVE_LEFT_1 || keycode == MOVE_RIGHT_1 ||
			keycode == Z_IN_2 || keycode == Z_OUT_2)
	{
		move(e, keycode);
		draw_image(e);
	}
	else if (keycode == LIGHTS_UP || keycode == LIGHTS_DOWN)
	{
		change_lights_intensity(e->scene, keycode);
		draw_image(e);
	}
	else if (keycode == LOCK_C)
		e->lights_lock = (e->lights_lock) ? 0 : 1;
}

void	change_lights_intensity(t_scene *scene, int keycode)
{
	int i;

	i = 0;
	if (keycode == LIGHTS_UP)
		while (i < scene->light_nr)
		{
			scene->light[i].intensity = (scene->light[i].intensity < 2.000f
					? scene->light[i].intensity + 0.100f
					: scene->light[i].intensity);
			i++;
		}
	else if (keycode == LIGHTS_DOWN)
		while (i < scene->light_nr)
		{
			scene->light[i].intensity = (scene->light[i].intensity > 0.000f
					? scene->light[i].intensity - 0.100f
					: scene->light[i].intensity);
			i++;
		}
}
