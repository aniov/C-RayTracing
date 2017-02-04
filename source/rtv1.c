/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:25:39 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 18:26:19 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ini_somestuff(t_env *e)
{
	e->obj_angle.x = 0;
	e->obj_angle.y = 0;
	e->obj_angle.z = 0;
	e->lights_angle.x = 0;
	e->lights_angle.y = 0;
	e->lights_angle.z = 0;
	e->lights_lock = 0;
	e->scene->rayx = 0;
	e->scene->rayy = 0;
	e->scene->rayz = 1;
}

void	create_window(t_env *e)
{
	ini_somestuff(e);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "RTv1");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}

int		read_input(t_env *e, char *str)
{
	e->scene = (t_scene*)malloc(sizeof(t_scene));
	if ((ft_strcmp(str, "1\0") == 0))
		scene_one(e->scene);
	else if ((ft_strcmp(str, "2\0") == 0))
		scene_two(e->scene);
	else if ((ft_strcmp(str, "3\0") == 0))
		scene_three(e->scene);
	else if ((ft_strcmp(str, "4\0") == 0))
		scene_four(e->scene);
	else if ((ft_strcmp(str, "5\0") == 0))
		scene_five(e->scene);
	else if ((ft_strcmp(str, "6\0") == 0))
		scene_six(e->scene);
	else if ((ft_strcmp(str, "7\0") == 0))
		scene_seven(e->scene);
	else if ((ft_strcmp(str, "8\0") == 0))
		scene_eight(e->scene);
	else if ((ft_strcmp(str, "9\0") == 0))
		scene_nine(e->scene);
	else
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc == 2 && read_input(&e, argv[1]))
		create_window(&e);
	return (0);
}
