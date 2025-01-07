/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: snijhuis <snijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/04 16:10:50 by snijhuis      #+#    #+#                 */
/*   Updated: 2024/04/04 16:11:34 by snijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_adress;

	temp = *lst;
	if (!*lst || !del)
		return ;
	while (temp != NULL)
	{
		temp_adress = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_adress;
	}
	*lst = NULL;
	return ;
}
