/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:06:12 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/20 13:52:14 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

//TODO:Remove this libs...
# include <stdio.h>
# include <string.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_head
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				median_idx;
	int				*sorted_arr;
	int				ra;
	int				rb;
	int				pa;
	int				pb;
}	t_head;

void	sort_three_a(t_head *head);

/* init.c */
t_head	*init(int ac, char **av);
void	init_array(t_stack *stack, t_head *head);

/* quick_sort.c */
int		*quick_sort(int *arr, int left, int right);

/* print.c */
void	print(t_head *head);

/* stack.c */
t_stack	*init_stack(int ac, char **av);
void	free_stack(t_stack *stack);

/* swap.c */
void	sa(t_head	*head);
void	sb(t_head	*head);
void	ss(t_head	*head);

/* push.c */
void	pb(t_head	*head);
void	pa(t_head	*head);

/* rotate.c */
void	ra(t_head *head);
void	rb(t_head *head);
void	rr(t_head *head);

/* reverse_rotate.c */
void	rra(t_head *head);
void	rrb(t_head *head);
void	rrr(t_head *head);

/* push_swap.c */
int		a_is_sorted(t_head *head, int start_idx);
// void	a_to_b(t_head *head, int pivot, int count);
void	b_to_a(t_head *head, int pivot_a, int pivot_b, int count);
void	a_to_b(t_head *head, int pivot_a, int pivot_b, int count);
// void	b_to_a(t_head *head, int pivot, int count);
int	stack_length(t_stack *stack);

#endif
