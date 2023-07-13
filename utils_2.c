/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:35 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 06:26:53 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_min(t_list *stack_a, int *max, int *min, int i_min_max[2])
{
	int	i;

	i = 1;
	while (stack_a)
	{
		if (stack_a->num >= *max)
		{
			*max = stack_a->num;
			i_min_max[0] = i;
		}
		else if (stack_a->num < *min)
		{
			*min = stack_a->num;
			i_min_max[1] = i - 1;
		}
		i++;
		stack_a = stack_a->next;
	}
}

int	ft_check_is_min_or_max(t_list *stack_a, int num)
{
	int		min;
	int		max;
	int		i_min_max[2];

	min = stack_a->num;
	max = stack_a->num;
	i_min_max[0] = 0;
	i_min_max[1] = 0;
	max_min(stack_a, &max, &min, i_min_max);
	if (num > max)
		return (i_min_max[0]);
	else if (num < min)
		return (i_min_max[1]);
	return (1337);
}

int	the_best_move(t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		pos;
	int		index_pos;

	i = 0;
	index_pos = 0;
	tmp = *stack_b;
	pos = tmp->best_move;
	while (tmp)
	{
		if (tmp->best_move < pos)
		{
			pos = tmp->best_move;
			index_pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index_pos);
}

void	give_index(t_list **stack_b, int *b_index, int *b_in_a_i, int *i_pos)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (i == *i_pos)
		{
			*b_index = tmp->b_index;
			*b_in_a_i = tmp->b_in_a_index;
		}
		tmp = tmp->next;
		i++;
	}
}

void	do_instructions(t_list **stack_a, t_list **stack_b, int b, int a)
{
	while (a > 0 && b > 0)
	{
		rr(stack_a, stack_b, 1);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		rrr(stack_a, stack_b, 1);
		a++;
		b++;
	}
	action_a(stack_a, a);
	action_b(stack_b, b);
}
