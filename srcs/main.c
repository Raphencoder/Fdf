/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:58:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/01 15:41:44 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*str;
	s_check	numb;

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
	str = ft_take_doc(fd, &numb.line);
	ft_all(str, &numb);
	return (0);
}
