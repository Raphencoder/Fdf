srcs/ft_all.c:	pos->tab = ft_parsing(str, pos);
srcs/ft_checkgrid.c:	pos->nb = numb->nbl;
srcs/ft_checkgrid.c:	error = error + pos->line - numb->fline;
srcs/ft_graph.c:	i = (x * 4) + (y * pos->s_l);
srcs/ft_graph.c:	if (x < pos->s_l / 4 && y < 2000 && x >= 0 && y >= 0)
srcs/ft_graph.c:		pos->img_str[i + 2] = (char)255;
srcs/ft_graph.c:		pos->img_str[i + 1] = (char)255;
srcs/ft_graph.c:		pos->img_str[i] = (char)0;
srcs/ft_graph.c:	x *= pos->rotatex;
srcs/ft_graph.c:	y *= pos->rotatey;
srcs/ft_graph.c:	new.x = x + pos->movex + (z * pos->h);
srcs/ft_graph.c:	new.y = y + pos->movey - (z * pos->h);
srcs/ft_graph.c:	while (i < pos->line)
srcs/ft_graph.c:		while (j < pos->nb)
srcs/ft_graph.c:			cord = ft_convert(j, i, pos->tab[i][j], pos);
srcs/ft_graph.c:				ft_put_line(cord, ft_convert(j - 1, i, pos->tab[i][j - 1], pos), pos);
srcs/ft_graph.c:				ft_put_line(cord, ft_convert(j, i - 1, pos->tab[i - 1][j], pos), pos);
srcs/ft_parsing.c:	tab = (int**)malloc(sizeof(int*) * (pos->line + 1));
srcs/ft_parsing.c:		tab[j] = (int*)malloc(sizeof(int) * (pos->nb));
srcs/key_hook.c:		pos->movex -= 20;
srcs/key_hook.c:		pos->movex += 20;
srcs/key_hook.c:		pos->movey -= 10;
srcs/key_hook.c:		pos->movey += 10;
srcs/key_hook.c:		pos->h = pos->h * 1.1;
srcs/key_hook.c:		pos->h = pos->h / 1.1;
srcs/key_hook.c:		pos->rotatex /= 1.1;
srcs/key_hook.c:		pos->rotatey /= 1.1;
srcs/key_hook.c:		pos->h = pos->h / 1.1;
srcs/key_hook.c:		pos->rotatex *= 1.1;
srcs/key_hook.c:		pos->rotatey *= 1.1;
srcs/key_hook.c:		pos->h = pos->h * 1.1;
srcs/key_hook.c:			pos->rotatex -= 5;
srcs/key_hook.c:			pos->movex += 45;
srcs/key_hook.c:			pos->rotatex += 5;
srcs/key_hook.c:			pos->movex -= 45;
srcs/key_hook.c:		if (pos->rotatex < -95)
srcs/key_hook.c:		if (pos->rotatex > 95)
srcs/key_hook.c:		pos->rotatex += 5;
srcs/key_hook.c:		pos->movex -= 45;
srcs/key_hook.c:		pos->rotatey -= 5;
srcs/key_hook.c:		pos->movey += 22;
srcs/key_hook.c:		pos->rotatey += 5;
srcs/key_hook.c:		pos->movey -= 22;
srcs/key_hook.c:	mlx_destroy_image(pos->mlx_ptr, pos->ptr_img);
srcs/key_hook.c:	pos->ptr_img = mlx_new_image(pos->mlx_ptr, 3000, 2000);
srcs/key_hook.c:	mlx_put_image_to_window(pos->mlx_ptr, pos->win_ptr, pos->ptr_img, 0, 0);
