/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coef.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 11:10:42 by Raphael           #+#    #+#             */
/*   Updated: 2018/02/21 22:07:09 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	change_coef(float *coefx, float *coefy, int x, int y)
{
	if (x == 0)
	{
		*coefx = 0;
		*coefy = 1;
	}
	else if (y == 0)
	{
		*coefy = 0;
		*coefx = 1;
	}
	else
	{
		*coefx = (float)x / (float)y;
		*coefy = (float)y / (float)x;
	}
	if (*coefx >= 1)
		*coefx = 1;
	else
		*coefy = 1;
}

void	ft_get_coef(t_new corda, t_new cordb, float *coefx, float *coefy)
{
	int x;
	int y;

	x = ABS((corda.x - cordb.x));
	y = ABS((corda.y - cordb.y));
	change_coef(coefx, coefy, x, y);
	if (cordb.x - corda.x < 0)
		*coefx = -(*coefx);
	if (cordb.y - corda.y < 0)
		*coefy = -(*coefy);
}
