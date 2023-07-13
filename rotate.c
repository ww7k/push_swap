/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:17 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:03:18 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*last_node;
	t_list	*tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	last_node = ft_last_node(*stack);
	tmp = *stack;
	(*stack) = (*stack)->next;
	last_node->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **stack_a, int i)
{
	rotate(stack_a);
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int i)
{
	rotate(stack_b);
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int i)
{
	rotate(stack_a);
	rotate(stack_b);
	if (i == 1)
		write(1, "rr\n", 3);
}
