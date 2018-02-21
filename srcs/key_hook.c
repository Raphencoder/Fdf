/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:10:46 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/20 14:49:04 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

int		key_hook(int kc, s_pos *pos)
{
	static int state = 1;
	printf("%d\n", kc);
	if (kc == 123)
		pos->movex -= 20;
	if (kc == 124)
		pos->movex += 20;
	if (kc == 126)
		pos->movey -= 10;
	if (kc == 125)
		pos->movey += 10;
	if (kc == 69)
		pos->h = pos->h * 1.1;
	if (kc == 78)
		pos->h = pos->h / 1.1;
	if (kc == 121)
	{
		pos->rotatex /= 1.1;
		pos->rotatey /= 1.1;
		pos->h = pos->h / 1.1;
	}
	if (kc == 116)
	{
		pos->rotatex *= 1.1;
		pos->rotatey *= 1.1;
		pos->h = pos->h * 1.1;
	}
	if (kc == 0)
	{
		if (state == 1)
		{
			pos->rotatex -= 5;
			pos->movex += 45;
		}
		else if (state == 2)
		{
			pos->rotatex += 5;
			pos->movex -= 45;
		}
		if (pos->rotatex < -95)
			state = 2;
		if (pos->rotatex > 95)
			state = 1;
	}
	if (kc == 2)
	{
		pos->rotatex += 5;
		pos->movex -= 45;
	}
	if (kc == 13)
	{
		pos->rotatey -= 5;
		pos->movey += 22;
	}
	if (kc == 6)
	{
		pos->rotatey += 5;
		pos->movey -= 22;
	}
	mlx_destroy_image(pos->mlx_ptr, pos->ptr_img);
	pos->ptr_img = mlx_new_image(pos->mlx_ptr, 3000, 2000);
	ft_graph(pos);
	mlx_put_image_to_window(pos->mlx_ptr, pos->win_ptr, pos->ptr_img, 0, 0);
	return (0);
}
