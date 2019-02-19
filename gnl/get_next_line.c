/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:50:58 by gquence           #+#    #+#             */
/*   Updated: 2019/02/19 18:48:58 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdlib.h>

static	char	*ft_get_line()

static	t_list	*ft_corr_file(t_list **file, const int fd)
{
	t_list		*lst;

	if (fd < 0 || !file || !*file)
		return (NULL);
	lst = *file;
	while (lst->next)
	{
		if (lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	if (!(lst = ft_lstnew("", fd)))
		return (NULL);
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char			*content;

	if (fd < 0 || !line || (BUF_SIZE < 1))
		return (-1);
	if (!(curr = ft_corr_file(&curr, fd)))
		return (-1);
}
