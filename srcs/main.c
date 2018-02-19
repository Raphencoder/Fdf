/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:58:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/19 19:26:20 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	int 	bpp;
	int		endian;
	char	*str;
	s_check	numb;
	s_pos	pos;

	ft_bzero(&numb, sizeof(s_check));
	ft_bzero(&pos, sizeof(s_pos));
	pos.h = 1;
	pos.movex = 150;
	pos.movey = 150;
	pos.rotatex = 100;
	pos.rotatey = 100;
	if (argc != 2)
	{
		ft_putendl("errror");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (read(fd, 0, 0) < 0)
	{
		ft_putendl("error");
		return (0);
	}
	str = ft_take_doc(fd, &pos.line);
	pos.mlx_ptr = mlx_init();
  	pos.win_ptr = mlx_new_window(pos.mlx_ptr, 3000, 2000, "fdf");
	pos.ptr_img = mlx_new_image(pos.mlx_ptr, 3000, 2000);
	pos.img_str = mlx_get_data_addr(pos.ptr_img, &(bpp), &(pos.s_l), &(endian));
	ft_all(str, &numb, &pos);
	mlx_put_image_to_window(pos.mlx_ptr, pos.win_ptr, pos.ptr_img, 0, 0);
	mlx_hook(pos.win_ptr, 2, 3, key_hook, &pos);
	mlx_loop(pos.mlx_ptr);
	return (0);
}
