

static	char	*ft_get_line(t_list **plst)
{
	char		*str;
	t_list		*lst;
	char		*line;
	size_t		len;
	char		*content;

	if (!plst || !*plst)
		return (NULL);
	lst = *plst;
	line = (char *)(lst->content);
	len = 0;
	while (*(line + len) && *(line + len) != '\n')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	content = strdup((line + len + 1));
	*(str + len) = 0;
	while (len--)
		*(str + len) = *(line + len);
	free((lst->content));
	lst->content = content;
	return (str);
}

static	t_list	*ft_corr_file(t_list **file, const int fd)
{
	t_list		*lst;

	if (fd < 0 || !file)
		return (NULL);
	
	if (!*file)
		return (*file = ft_lstnew("", fd));
	lst = *file;
	while (lst)
	{
		if (lst->content_size == fd && *(lst->content))
			return (lst);
		lst = lst->next;
	}
	lst = ft_lstnew("\0", fd);
	ft_lstadd(file, lst);
	lst = *file;
	return (lst);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*curr;
	char			*content;
	char			buf[BUF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || (BUF_SIZE < 1)  || !(curr = ft_corr_file(&file, fd)))
		return (-1);
	while ((ret = read(fd, &buf, BUF_SIZE)))
	{
		buf[ret] = 0;
		content = strdup((char *)(curr->content));
		free(curr->content);
		curr->content = (char *)malloc(sizeof(char) * (ret + ft_strlen(content) + 1));
		curr->content = ft_strcpy((char *)(curr->content), content);
		curr->content = ft_strcat((char *)(curr->content), buf);
		free(content);
		if (ret != BUF_SIZE || ft_strchr((char *)(curr->content), '\n'))
			break;
	}
	*line = ft_get_line(&curr);
	if (ret == BUF_SIZE || (char)(*(curr->content)))
		return (1);
	return (0);
}



int	main()
{
	char s1[] = "ft_atoi.c";
	char s2[] = "get_next_line.h";

	int fd1 = open((char *)s2, O_RDONLY);
	int fd2 = open((char *)s2, O_RDONLY);
	char	*line1;
	char	*line2;
	int ret1;
//	cout << line;
	while ((ret1 = get_next_line(fd1, &line1)) == 1)
	{
		cout << line1 << endl;
		free(line1);
	}
	cout << line1 << endl;
	free(line1);
	while ((ret1 = get_next_line(fd2, &line2)) == 1)
	{
		cout << line2 << endl;
		free(line2);
	}
	cout << line2 << endl;
	free(line2);
	system("pause");
	_CrtDumpMemoryLeaks();
	return (0);
}
