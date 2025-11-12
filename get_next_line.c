/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-achh <hel-achh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:11:49 by hel-achh          #+#    #+#             */
/*   Updated: 2025/11/12 21:16:36 by hel-achh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_linked_list(t_list **head, char *str, t_list **node)
{
	t_list	*temp;

	if (str)
	{
		(*node)->value = str;
		(*node)->next = NULL;
		return ;
	}
	else
	{
		if (!*head)
			return ;
		while (*head)
		{
			temp = (*head)->next;
			free((*head)->value);
			free(*head);
			*head = temp;
		}
		*head = NULL;
	}
}

static int	create_linked_list(t_list **head, int fd)
{
	char	*value;
	int		chars_readed;

	while (!is_there_line(*head))
	{
		value = (char *)malloc(BUFFER_SIZE + 1);
		if (!value)
			return (free_linked_list(head, NULL, NULL), -1);
		chars_readed = read(fd, value, BUFFER_SIZE);
		if (chars_readed <= 0)
		{
			if(chars_readed == -1)
			{
				free_linked_list(head, NULL, NULL);
				return (free(value), -1);
			}
			return (free(value), 1);
		}
		value[chars_readed] = '\0';
		push_at_back(head, value);
	}
	return 1;
}

static char	*get_characters_to_line(t_list *head)
{
	char	*line;
	int		n;
	int		i;

	line = (char *)malloc(sizeof(char) * (size_to_line(head) + 1));
	if (!line)
		return (NULL);
	n = 0;
	while (head)
	{
		i = 0;
		while (head->value[i])
		{
			line[n++] = head->value[i];
			if (head->value[i++] == '\n')
			{
				line[n] = '\0';
				return (line);
			}
		}
		head = head->next;
	}
	line[n] = '\0';
	return (line);
}

static void	reset_linked_list(t_list **head)
{
	t_list	*last;
	char	*rest;
	int		i;

	i = 0;
	if (!head || !*head)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	while (last->value[i] && last->value[i] != '\n')
		i++;
	if (last->value[i] == '\n')
		i++;
	if (!last->value[i])
		return (free_linked_list(head, NULL, NULL));
	rest = malloc(ft_strlen(last->value + i) + 1);
	if (!rest)
		return (free_linked_list(head, NULL, NULL));
	ft_strcpy(rest, last->value + i);
	free_linked_list(head, NULL, NULL);
	*head = (t_list *)malloc(sizeof(t_list));
	if (!*head)
		return (free(rest));
	free_linked_list(NULL, rest, head);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	if (create_linked_list(&head, fd) == -1)
		return NULL;
	if (!head)
		return (NULL);
	line = get_characters_to_line(head);
	if (!line || line[0] == '\0')
	{
		free_linked_list(&head, NULL, NULL);
		return (NULL);
	}
	reset_linked_list(&head);
	return (line);
}
