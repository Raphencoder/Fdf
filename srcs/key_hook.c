/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:10:46 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:09:46 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	key_hook1(int kc, t_pos *pos)
{
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
}

void	key_hook2(int kc, t_pos *pos)
{
	if (kc == 69)
	{
		if (pos->h > 1000)
			pos->h *= 1.00000000000000001;
		else
			pos->h = pos->h * 1.1;
	}
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
}

int		key_hook(int kc, t_pos *pos)
{
	key_hook1(kc, pos);
	key_hook2(kc, pos);
	handlekc(kc, pos);
	mlx_destroy_image(pos->mlx_ptr, pos->ptr_img);
	pos->ptr_img = mlx_new_image(pos->mlx_ptr, 3000, 2000);
	ft_graph(pos);
	mlx_put_image_to_window(pos->mlx_ptr, pos->win_ptr, pos->ptr_img, 0, 0);
	return (0);
}
