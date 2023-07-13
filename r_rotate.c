/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:13 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:02:44 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **stack)
{
	t_list	*b_last;
	t_list	*last;
	t_list	*tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	last = ft_last_node(*stack);
	tmp = (*stack);
	(*stack) = last;
	b_last = ft_before_last_node(tmp);
	b_last->next = NULL;
	(*stack)->next = tmp;
}

void	rra(t_list **stack_a, int i)
{
	r_rotate (stack_a);
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int i)
{
	r_rotate (stack_b);
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b, int i)
{
	r_rotate (stack_a);
	r_rotate (stack_b);
	if (i == 1)
		write(1, "rrr\n", 4);
}
