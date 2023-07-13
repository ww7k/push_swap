/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:24:50 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 00:55:02 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(int num)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	return (node);
}

t_list	*ft_last_node(t_list *node)
{
	while (node && node->next)
	{
		node = node->next;
	}
	return (node);
}

t_list	*ft_before_last_node(t_list *node)
{
	while (node && node->next && node->next->next)
	{
		node = node->next;
	}
	return (node);
}

int	lst_size(t_list *head)
{
	int	i;

	i = 1;
	while (head && head->next)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	add_back(t_list **head, t_list *node)
{
	t_list	*last_node;

	if (*head == NULL)
		*head = node;
	else
	{
		last_node = ft_last_node(*head);
		last_node->next = node;
	}
}
