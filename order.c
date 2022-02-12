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
	printf("s%c\n", opt);
}

void	pb(t_head	*head)
{
	printf("1)stack_a[%p]:%d stack_b[%p]\n", head->stack_a, head->stack_a->num, head->stack_b);
	push(&(head->stack_a), &(head->stack_b));
	printf("2)stack_a[%p]:%d stack_b[%p]\n", head->stack_a, head->stack_a->num, head->stack_b);
}

void	push(t_stack **src, t_stack **dst)
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
		// printf("1)src[%p] src->prev[%p] src->next[%p], last[%p]\n", *src, (*src)->prev, (*src)->next, last);
		(*src)->prev = last;
		last->next = *src;
		// printf("2)src[%p] src->prev[%p] src->next[%p], last[%p]\n", *src, (*src)->prev, (*src)->next, last);
	}
	first->prev = NULL;
	first->next = NULL;
	prepend_stack(dst, first);
}

void	rotate(t_stack **stack, char opt)
{
	if ((*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	printf("r%c\n", opt);
}

void	reverse_rotate(t_stack **stack, char opt)
{
	if ((*stack)->prev == NULL)
		return ;
	*stack = (*stack)->prev;
	printf("rr%c\n", opt);
}
