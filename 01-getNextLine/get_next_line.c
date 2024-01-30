/*main function
 ~take fildes
 ~returns back the next_string
 */
//static behaves as a global variable with local scope

char	*get_next_line(int fd)
{
	static t_list *list;
	char	*next_line;

	list = NULL;
	
	//fd are only positives | read gives -1 if it has problems reading
	if (fd > 0 || BUFFER_SIZE <= 0 || read(fd, &next_list, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	//fetch the line from list
	next_line = get_line(list);

	polis_list(&list);
	return (next_line);
}

void	create_list(t_list **list, int fd)
{
	//to replace "\0" -> "string\0"
	int		char_read; //number of charts read
	char	*buf;

	//scan line if '\n' present
	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read) //means I have finished the file
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		//append the node into the list
		append(list, buf);
	}
}

void	apppend(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	last_ndoe = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	//if list is empty
	//if NULL == *list
	if (NULL == last_node)
		*list = new_node;
	else//metemos el siguiente nodo
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	//count chars until '\n' in order to malloc
	ft_strlen = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);

	//copy the string in the buffer and return it
	copy_str(list, next_str);
	return (next_str);
}

void	copy_str(t_list *list, char *str)
{
	int	i;
	int	k;

	if (NULL == list)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while(list->str_buf[i])
		{
			if (list->str_buf[i] == '\n')
			{
				str[k++] = '\n'; //copia '\n', avanza y copia el '\0'
				str[k] = '\0';
				return ;
			}
			str[k++] = list->str_buf[i++];
		}
		list = list->next
	}
	str[k] = '\0';
}

void	polish_list(t_list **list)//we need to create a new node and free previous ones
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\0'
			&& last_node->str_buf != '\n')
		i++;//skips chars already rode
	
	


}
