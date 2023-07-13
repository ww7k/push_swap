/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:01 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/07 04:40:58 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-'))
		i++;
	if (!argv[i])
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (0);
}

void	duplicated(t_list *stack)
{
	int		tmp;
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = stack;
	tmp2 = stack;
	while (tmp1)
	{
		tmp = tmp1->num;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp == tmp2->num)
			{
				write(1, "Error\n", 6);
				free_stack(&stack);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

void	ft_error(char *line)
{
	write (1, "Error\n", 6);
	if (line)
		free(line);
	exit (1);
}

void	get_num(t_list **stack_a, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**str;
	t_list	*tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		j = 0;
		if (str[j] == NULL)
			ft_error(NULL);
		while (str[j])
		{
			check_args(str[j]);
			num = ft_atoi(str[j]);
			tmp = ft_new_node(num);
			add_back(stack_a, tmp);
			j++;
		}
		free_str(str);
		i++;
	}
}
