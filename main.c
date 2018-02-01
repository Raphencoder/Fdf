/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:09:14 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/18 17:01:03 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int	my_key_funct(int keycode, void *param)
{
	void *res;
	void *wind;

	printf("key event %d\n", keycode);
	mlx_pixel_put(res, wind, 300, 300, 0xFF00FF);
	return (0);
}

int main()
{
	void *res;
	void *wind;
	int		x;
	int		y;

	res = mlx_init();
	y = 50;
	wind = mlx_new_window(res, 800, 400, "fdfbegin");
	while (y < 300)
	{
		x = 50;
		while (x < 600)
		{
			mlx_pixel_put(res, wind, x, y, 0x00FFFFFF);
			x += 5;
		}
		y += 5;
	}
	mlx_key_hook(wind, my_key_funct, 0);
	mlx_loop(res);
	return (0);
}
