/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:13:35 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/04/04 16:13:43 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list *ft_lstnew(void *content);

// int main (void)
// {
//     int test = 66;
//     t_list *node = ft_lstnew(&test);

//      if (*(int *)node->content == test) {
//         printf("Content is correct: %d\n", *(int *)node->content);
//     }
//         else
//     {
//         printf("Content is incorrect.\n");
//     }
//     return (0);
// }

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
