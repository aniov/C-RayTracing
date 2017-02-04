/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:00:49 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 19:01:08 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	vector_cross(t_vect *v1, t_vect *v2)
{
	t_vect res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}

double	vector_lenght(t_vect *v)
{
	return (sqrt(vector_dot(v, v)));
}

t_vect	vector_normalised(t_vect *v)
{
	double lenght;
	t_vect norm;

	lenght = vector_lenght(v);
	norm.x = v->x / lenght;
	norm.y = v->y / lenght;
	norm.z = v->z / lenght;
	return (norm);
}
