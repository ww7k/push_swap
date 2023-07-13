/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:21 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:06:15 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		if ((*stack)->num < (*stack)->next->next->num)
			sa(stack, 1);
		else if ((*stack)->next->num > (*stack)->next->next->num)
		{
			sa(stack, 1);
			rra(stack, 1);
		}
		else if ((*stack)->num > (*stack)->next->next->num)
			ra(stack, 1);
	}
	else if ((*stack)->num < (*stack)->next->num)
	{
		if ((*stack)->next->num < (*stack)->next->next->num)
			return ;
		else if ((*stack)->num < (*stack)->next->next->num)
		{
			sa(stack, 1);
			ra(stack, 1);
		}
		else if ((*stack)->next->num > (*stack)->next->next->num)
			rra(stack, 1);
	}
}

void	find_min(t_list **stack_a)
{
	int		i;
	int		i_min;
	int		min;
	int		size;
	t_list	*tmp;

	i_min = 0;
	i = 0;
	size = lst_size(*stack_a);
	tmp = *stack_a;
	min = tmp->num;
	while (i < size)
	{
		if (min > tmp->num)
		{
			min = tmp->num;
			i_min = i;
		}
		tmp = tmp->next;
		i++;
	}
	i = indx_size(size, i_min);
	action_a(stack_a, i);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	int		k;
	int		size;

	k = 2;
	size = lst_size(*stack_a);
	while (k > (5 - size))
	{
		find_min(stack_a);
		pb(stack_a, stack_b, 1);
		k--;
	}
	ft_sort_3(stack_a);
	pa(stack_b, stack_a, 1);
	pa(stack_b, stack_a, 1);
}
