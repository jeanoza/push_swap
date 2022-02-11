/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:57:07 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/08 20:38:57y kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char opt)
{
	int	tmp;

	if (stack->next == NULL)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	if (opt == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	push(t_stack **src, t_stack **dst, char opt)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	if (first == NULL)
		return ;
	last = first->prev;
	*src = first->next;
	if (*(src) == first)
		*src = NULL;
	else
	{
		(*src)->prev = last;
		last->next = *src;
	}
	first->prev = NULL;
	first->next = NULL;
	prepend_stack(dst, first);
	if (opt == 0)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

void	rotate(t_stack **stack, char opt)
{
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	if (opt == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, char opt)
{
	if ((*stack)->prev == NULL)
		return ;
	*stack = (*stack)->prev;
	if (opt == 0)
		write(1, "rra\n", 3);
	else
		write(1, "rrb\n", 3);
}
