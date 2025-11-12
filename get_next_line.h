/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-achh <hel-achh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:52:08 by hel-achh          #+#    #+#             */
/*   Updated: 2025/11/10 20:48:57 by hel-achh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	char			*value;
	struct s_list	*next;
}				t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		is_there_line(t_list *head);
void	push_at_back(t_list **head, char *value);
int		size_to_line(t_list *head);
char	*get_next_line(int fd);
size_t	ft_strlen(const char	*s);
char	*ft_strcpy(char *dest, const char *src);

#endif
