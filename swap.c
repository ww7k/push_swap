/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:27 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:03:46 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = tmp;
}

void	sa(t_list **stack_a, int i)
{
	swap(stack_a);
	if (i == 1)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int i)
{
	swap(stack_b);
	if (i == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b, int i)
{
	swap(stack_a);
	swap(stack_b);
	if (i == 1)
		write(1, "ss\n", 3);
}
