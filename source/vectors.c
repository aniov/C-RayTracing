/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:59:47 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:00:33 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	vector_add(t_vect *v1, t_vect *v2)
{
	t_vect res;

	res.x = v1->x + v2->x;
	res.y = v1->y + v2->y;
	res.z = v1->z + v2->z;
	return (res);
}

t_vect	vector_sub(t_vect *v1, t_vect *v2)
{
	t_vect res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return (res);
}

double	vector_dot(t_vect *v1, t_vect *v2)
{
	double res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

t_vect	vector_scale(double nr, t_vect *v)
{
	t_vect res;

	res.x = v->x * nr;
	res.y = v->y * nr;
	res.z = v->z * nr;
	return (res);
}
