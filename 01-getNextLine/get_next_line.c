/*main function
 ~take fildes
 ~returns back the next_string
 */
//static behaves as a global variable with local scope
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list *list;
	char	*next_line;

	list = NULL;
	
	//fd are only positives | read gives -1 if it has problems reading
	if (fd > 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	//fetch the line from list
	next_line = get_line(list);

	polish_list(&list);
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

void	append(t_list **list, char *buf)
{
	t_list *new_node;
	t_list *last_node;

	last_node = find_last_node(*list);
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
	int		str_lenght;
	char	*next_str;

	if (NULL == list)//so that if I reference an old pointer I get segfault
		return (NULL);
	//count chars until '\n' in order to malloc
	str_lenght = len_to_newline(list);
	next_str = malloc(str_lenght + 1);
	if (NULL == next_str)
		return (NULL);

	//copy the string in the buffer and return it
	copy_str(list, next_str);
	return (next_str);
}

void	polish_list(t_list **list)//we need to create a new node and free previous ones
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);//last chars of previous buffer before list = list->next
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);

	i = 0;
	k = 0;
	while (last_node->str_buf[i] != '\0'
			&& last_node->str_buf[i] != '\n')
		i++;//skips chars already rode
	while (last_node->str_buf[i] != '\0'
			&& last_node->str_buf[++i])//files with only '\0'. no new line(\n)
		buf[k++] = last_node->str_buf[i];
	buf[k] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);//hay que ver si se puede usar
}
