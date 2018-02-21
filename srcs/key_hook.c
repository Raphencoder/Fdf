/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:10:46 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 19:20:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		key_hook(int kc, s_pos *pos)
{
	static int state = 1;
	static int status = 1;
	static int stat = 1;
	static int ustate = 1;

	ft_putnbr(kc);
	ft_putchar('\n');	
	if (kc == 15)
	{
		pos->movex = 150;
		pos->movey = 150;
		pos->rotatex = 100;
		pos->rotatey = 100;
		pos->h = 1;
		state = 1;
		status = 1;
		stat = 1;
		ustate = 1;
	}
	if (kc == 53)
		exit(0);
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
		if (stat == 1)
		{
		pos->rotatex += 5;
		pos->movex -= 45;
		}
		else
		{
			pos->rotatex -= 5;
			pos->movex += 45;
		}
		if (pos->rotatex > 119)
			stat = 2;
		if (pos->rotatex < -85)
			stat = 1;
	}
	if (kc == 13)
	{
		if (status == 1)
		{
		pos->rotatey -= 5;
		pos->movey += 22;
		}
		else
		{
			pos->rotatey += 5;
			pos->movey -= 22;
		}
		if (pos->rotatey < -95)
			status = 2;
		if (pos->rotatey > 95)
			status = 1;
	}
	if (kc == 6)
	{
		if (ustate == 1)
		{		
		pos->rotatey += 5;
		pos->movey -= 22;
		}
		else
		{
			pos->rotatey -= 5;
			pos->movey += 22;		
		}
		if (pos->rotatey > 100)
			ustate = 2;
		if (pos->rotatey < -90)
			ustate = 1;
	}
	mlx_destroy_image(pos->mlx_ptr, pos->ptr_img);
	pos->ptr_img = mlx_new_image(pos->mlx_ptr, 3000, 2000);
	ft_graph(pos);
	mlx_put_image_to_window(pos->mlx_ptr, pos->win_ptr, pos->ptr_img, 0, 0);
	return (0);
}
