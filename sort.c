/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:24 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:09:58 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index_in_a(t_list *stack_a, int num)
{
	int		i;
	int		return_index;
	int		size;
	t_list	*lst_node;

	i = 0;
	return_index = 0;
	size = lst_size(stack_a);
	i = ft_check_is_min_or_max(stack_a, num);
	lst_node = ft_last_node(stack_a);
	if (i != 1337)
	{
		return_index = indx_size(size, i);
		return (return_index);
	}
	if (num > lst_node->num && num < stack_a->num)
		return (0);
	i = 1;
	while (!(num > stack_a->num && num < (stack_a->next)->num))
	{
		stack_a = stack_a->next;
		i++;
	}
	return_index = indx_size(size, i);
	return (return_index);
}

int	ft_get_best_move(int b, int a)
{
	int	result;

	result = 0;
	if ((b > 0 && a > 0) || (b < 0 && a < 0))
	{
		if (ft_abs(b) > ft_abs(a))
			result = ft_abs(b);
		else if (ft_abs(a) > ft_abs(b))
			result = ft_abs(a);
		else
			result = ft_abs(b);
	}
	else
		result = ft_abs(b) + ft_abs(a);
	return (result);
}

void	function(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	size = lst_size(*stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		tmp->b_index = indx_size(size, i);
		tmp->b_in_a_index = ft_get_index_in_a(*stack_a, tmp->num);
		tmp->best_move = ft_get_best_move(tmp->b_index, tmp->b_in_a_index);
		tmp = tmp->next;
		i++;
	}
}

void	ft_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int		index_pos;
	int		b_index;
	int		b_in_a_index;

	b_index = 0;
	b_in_a_index = 0;
	while (*stack_b)
	{
		function(stack_a, stack_b);
		index_pos = the_best_move(stack_b);
		give_index(stack_b, &b_index, &b_in_a_index, &index_pos);
		do_instructions(stack_a, stack_b, b_index, b_in_a_index);
		pa(stack_b, stack_a, 1);
	}
	find_min(stack_a);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	i = 1;
	size = lst_size(*stack_a);
	while (i <= (size - 3))
	{
		pb(stack_a, stack_b, 1);
		i++;
	}
	if (!is_sorted(*stack_a))
		ft_sort_3(stack_a);
	ft_back_to_a(stack_a, stack_b);
}
