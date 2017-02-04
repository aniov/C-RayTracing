/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 17:16:44 by mvoina            #+#    #+#             */
/*   Updated: 2016/02/16 17:49:38 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	helper_matrix_ini_x(t_env *e, double anglex)
{
	e->mat.x[0][0] = 1.0f;
	e->mat.x[0][1] = 0.0f;
	e->mat.x[0][2] = 0.0f;
	e->mat.x[1][0] = 0.0f;
	e->mat.x[1][1] = cosf(anglex);
	e->mat.x[1][2] = sinf(anglex);
	e->mat.x[2][0] = 0.0f;
	e->mat.x[2][1] = -sinf(anglex);
	e->mat.x[2][2] = cosf(anglex);
}

static void	helper_matrix_ini_y(t_env *e, double angley)
{
	e->mat.y[0][0] = cosf(angley);
	e->mat.y[0][1] = 0.0f;
	e->mat.y[0][2] = -sinf(angley);
	e->mat.y[1][0] = 0.0f;
	e->mat.y[1][1] = 1.0f;
	e->mat.y[1][2] = 0.0f;
	e->mat.y[2][0] = sinf(angley);
	e->mat.y[2][1] = 0.0f;
	e->mat.y[2][2] = cosf(angley);
}

static void	helper_matrix_ini_z(t_env *e, double anglez)
{
	e->mat.z[0][0] = cosf(anglez);
	e->mat.z[0][1] = sinf(anglez);
	e->mat.z[0][2] = 0.0f;
	e->mat.z[1][0] = -sinf(anglez);
	e->mat.z[1][1] = cosf(anglez);
	e->mat.z[1][2] = 0;
	e->mat.z[2][0] = 0.0f;
	e->mat.z[2][1] = 0.0f;
	e->mat.z[2][2] = 1.0f;
}

void		helper_matrix_ini(t_env *e, double anglex, double angley,
							double anglez)
{
	helper_matrix_ini_x(e, anglex);
	helper_matrix_ini_y(e, angley);
	helper_matrix_ini_z(e, anglez);
}

void		multiply_matrix(double first_mat[3][3], double scnd_mat[3][3],
		double result_mat[3][3])
{
	double	temp;
	int		a;
	int		b;
	int		c;

	a = 0;
	temp = 0;
	while (a < 3)
	{
		b = 0;
		while (b < 3)
		{
			c = 0;
			while (c < 3)
			{
				temp += first_mat[b][c] * scnd_mat[c][a];
				c++;
			}
			result_mat[b][a] = temp;
			temp = 0;
			b++;
		}
		a++;
	}
}
