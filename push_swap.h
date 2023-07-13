/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatik <wwatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 04:25:06 by wwatik            #+#    #+#             */
/*   Updated: 2023/07/12 18:57:39 by wwatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <libc.h>
# include "get_next_line.h"

typedef struct s_list
{
	struct s_list	*next;
	int				num;
	int				b_index;
	int				b_in_a_index;
	int				best_move;
	int				i_min;
	int				i_max;
}	t_list;

int		check_args(char *argv);
int		lst_size(t_list *head);
void	add_back(t_list **head, t_list *node);
void	push(t_list **stack_src, t_list **stack_dst);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);
void	sa(t_list **stack_a, int i);
void	sb(t_list **stack_b, int i);
void	ss(t_list **stack_a, t_list **stack_b, int i);
void	ra(t_list **stack_a, int i);
void	rb(t_list **stack_b, int i);
void	rr(t_list **stack_a, t_list **stack_b, int i);
void	rra(t_list **stack_a, int i);
void	rrb(t_list **stack_b, int i);
void	rrr(t_list **stack_a, t_list **stack_b, int i);
void	pa(t_list **stack_b, t_list **stack_a, int i);
void	pb(t_list **stack_a, t_list **stack_b, int i);
t_list	*ft_new_node(int num);
t_list	*ft_last_node(t_list *node);
t_list	*ft_before_last_node(t_list *node);
void	ft_sort_3(t_list **stack);
void	ft_sort_5(t_list **stack_a, t_list **stack_b);
void	find_min(t_list **stack_a);
void	ft_call(t_list **stack_a, t_list **stack_b);
void	duplicated(t_list *stack);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *stack);
int		indx_size(int size, int i_min);
void	find_min(t_list **stack_a);
void	action_a(t_list **stack_a, int a);
void	action_b(t_list **stack_b, int b);
int		ft_abs(int num);
void	free_stack(t_list **stack);
void	free_str(char **str);
int		ft_check_is_min_or_max(t_list *stack_a, int num);
int		the_best_move(t_list **stack_b);
void	give_index(t_list **stack_b, int *b_index, int *b_in_a_i, int *i_pos);
void	do_instructions(t_list **stack_a, t_list **stack_b, int b, int a);
int		ft_get_index_in_a(t_list *stack_a, int num);
int		ft_get_best_move(int b, int a);
char	**ft_split(char	*s, char c);
int		ft_atoi(char *str);
void	get_num(t_list **stack_a, char **argv);
void	ft_error(char *line);
void	duplicated(t_list *stack);
int		check_args(char *argv);
int		ft_strcmp(const char *s1, const char *s2);

#endif
