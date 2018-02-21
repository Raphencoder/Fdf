/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:58:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/21 22:05:43 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_init(t_pos *pos)
{
	pos->h = 1;
	pos->movex = 150;
	pos->movey = 150;
	pos->rotatex = 100;
	pos->rotatey = 100;
}

void	ft_window(t_pos *pos)
{
	pos->mlx_ptr = mlx_init();
	pos->win_ptr = mlx_new_window(pos->mlx_ptr, 3000, 2000, "fdf");
	pos->ptr_img = mlx_new_image(pos->mlx_ptr, 3000, 2000);
	pos->img_str = mlx_get_data_addr(pos->ptr_img, &(pos->bpp),
	&(pos->s_l), &(pos->endian));
}

int		error(int *fd, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("Error with the number of arguments");
		return (0);
	}
	*fd = open(argv[1], O_RDONLY);
	if (read(*fd, 0, 0) < 0)
	{
		ft_putendl("Error while trying to read the file");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*str;
	t_check	numb;
	t_pos	pos;

	ft_bzero(&numb, sizeof(t_check));
	ft_bzero(&pos, sizeof(t_pos));
	ft_init(&pos);
	if (!error(&fd, argc, argv))
		return (0);
	str = ft_take_doc(fd, &pos.line);
	ft_window(&pos);
	if (!ft_all(str, &numb, &pos))
		return (0);
	mlx_put_image_to_window(pos.mlx_ptr, pos.win_ptr, pos.ptr_img, 0, 0);
	mlx_hook(pos.win_ptr, 2, 3, key_hook, &pos);
	mlx_loop(pos.mlx_ptr);
	return (0);
}
