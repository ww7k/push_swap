/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:09 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:01:59 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*node;

	if (*stack_src == NULL)
		return ;
	node = *stack_src;
	(*stack_src) = (*stack_src)->next;
	node->next = (*stack_dst);
	(*stack_dst) = node;
}

void	pa(t_list **stack_b, t_list **stack_a, int i)
{
	push(stack_b, stack_a);
	if (i == 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int i)
{
	push(stack_a, stack_b);
	if (i == 1)
		write(1, "pb\n", 3);
}
