/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 04:27:31 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 07:04:50 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arguments(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack_a, 2);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b, 2);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a, 2);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b, 2);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack_b, stack_a, 2);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b, 2);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a, 2);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b, 2);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b, 2);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b, 2);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b, 2);
	else
		ft_error(line);
	free(line);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	get_num(&stack_a, argv);
	duplicated(stack_a);
	line = get_next_line(0);
	while (line)
	{
		arguments(line, &stack_a, &stack_b);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
