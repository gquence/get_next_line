/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:35:51 by gquence           #+#    #+#             */
/*   Updated: 2019/03/03 16:17:23 by gquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int			ft_get_line(t_list **plst, char **ent_line)
{
	char			*str;
	t_list			*lst;
	char			*line;
	size_t			len;
	char			*content;

	if (!plst || !*plst)
		return (0);
	lst = *plst;
	if (!(*(char *)(lst->content)))
		return (0);
	line = (char *)(lst->content);
	len = 0;
	while (*(line + len) && *(line + len) != '\n')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	*ent_line = str;
	content = ft_strdup((line + len + 1));
	*(str + len) = 0;
	while (len--)
		*(str + len) = *(line + len);
	free((lst->content));
	lst->content = content;
	return (1);
}

static	t_list		*ft_corr_file(t_list **file, const int fd)
{
	t_list			*lst;

	if (fd < 0 || !file)
		return (NULL);
	if (!*file)
		return (*file = ft_lstnew("", fd));
	lst = *file;
	while (lst)
	{
		if (lst->content_size == (size_t)fd && *((char *)lst->content))
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("", fd);
	ft_lstadd(file, lst);
	lst = *file;
	return (lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char			*content;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (BUFF_SIZE < 1) ||
		!(curr = ft_corr_file(&file, fd)))
		return (-1);
	while ((ret = read(fd, &buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		content = ft_strdup((char *)(curr->content));
		free(curr->content);
		curr->content = (char *)ft_strjoin(content, buf);
		free(content);
		if (ret != BUFF_SIZE || ft_strchr((char *)(curr->content), '\n'))
			break ;
	}
	return (ft_get_line(&curr, line));
}
