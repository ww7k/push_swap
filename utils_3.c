/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:32:55 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/12 18:58:36 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	indx_size(int size, int i_min)
{
	int	i;

	i = 0;
	if (i_min > (size / 2))
		i = i_min - size;
	else
		i = i_min;
	return (i);
}

void	ft_call(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	if (!is_sorted(*stack_a) && size == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a, 1);
	}
	else if (!is_sorted(*stack_a) && size == 3)
		ft_sort_3(stack_a);
	else if (!is_sorted(*stack_a) && size > 3 && size <= 5)
		ft_sort_5(stack_a, stack_b);
	else if (!is_sorted(*stack_a) && size > 5)
		ft_sort(stack_a, stack_b);
}
