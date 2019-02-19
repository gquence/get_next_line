/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:58 by gquence           #+#    #+#             */
/*   Updated: 2019/02/19 16:58:18 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*cur;
	char			*content;

	if (fd < 0 || !line)
		return (-1);
	
}
