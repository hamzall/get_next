/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-achh <hel-achh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:52:14 by hel-achh          #+#    #+#             */
/*   Updated: 2025/11/07 09:50:01 by hel-achh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

int	is_there_line(t_list *head)
{
	int	i;

	if (!head)
		return (0);
	while (head)
	{
		i = 0;
		while (head->value[i])
		{
			if (head->value[i] == '\n')
				return (1);
			i++;
		}
		head = head->next;
	}
	return (0);
}

void	push_at_back(t_list **head, char *valuee)
{
	t_list	*n;
	t_list	*temp;

	n = (t_list *)malloc(sizeof(t_list) * 1);
	if (!n)
		return (free(valuee));
	n->value = valuee;
	n->next = NULL;
	if (!head || !*head)
		*head = n;
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = n;
	}
}

int	size_to_line(t_list *head)
{
	int	c;
	int	i;

	if (!head)
		return (0);
	i = 0;
	c = 0;
	while (head)
	{
		i = 0;
		while (head->value[i])
		{
			c++;
			if (head->value[i] == '\n')
				return (c);
			i++;
		}
		head = head->next;
	}
	return (c);
}
