/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:31 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:08:22 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_a(t_list **stack_a, int a)
{
	if (a > 0)
	{
		while (a > 0)
		{
			ra(stack_a, 1);
			a--;
		}
	}
	else if (a < 0)
	{
		while (a < 0)
		{
			rra(stack_a, 1);
			a++;
		}
	}
}

void	action_b(t_list **stack_b, int b)
{
	if (b > 0)
	{
		while (b > 0)
		{
			rb(stack_b, 1);
			b--;
		}
	}
	else if (b < 0)
	{
		while (b < 0)
		{
			rrb(stack_b, 1);
			b++;
		}
	}
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
