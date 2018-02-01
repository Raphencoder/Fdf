/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:36:07 by rkrief            #+#    #+#             */
/*   Updated: 2018/01/31 11:44:12 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_take_doc(int fd, int *line)
{
	char *str;
	char *buf;
	char *tmp;

	tmp = 0;
	str = 0;
	while (get_next_line(fd, &buf))
	{
		tmp = str;
		if (str == NULL)
			str= ft_strdup(buf);
		else
			str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		str = tmp;
		str = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		*line = *line + 1;
	}
	return (str);
}
