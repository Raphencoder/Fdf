/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:36:07 by rkrief            #+#    #+#             */
/*   Updated: 2018/02/19 17:58:12 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_take_doc(int fd, int *line)
{
	char *str;
	char *buf;
	char *tmp;
	char *res;

	tmp = 0;
	str = 0;
	while (get_next_line(fd, &buf))
	{
		tmp = str;
		if (*line == 0)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = str;
		str = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		*line = *line + 1;
	}
	res = ft_strdup(str);
	ft_strdel(&str);
	return (res);
}
