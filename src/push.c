/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:05:53 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 17:39:18 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop(t_stack **stack)
{
	t_stack	*pop;

	if (!stack)
		return (NULL);
	if (!*stack)
		return (NULL);
	pop = *stack;
	if (*stack == (*stack)->next)
		*stack = 0;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
		pop->prev = pop;
		pop->next = pop;
	}
	return (pop);
}

static void	prepend(t_stack **stack_list, t_stack *new_stack)
{
	if (!stack_list || !new_stack)
		return ;
	if (*stack_list)
	{
		(*stack_list)->prev->next = new_stack;
		new_stack->prev = (*stack_list)->prev;
		(*stack_list)->prev = new_stack;
		new_stack->next = *stack_list;
	}
	*stack_list = new_stack;
}

void	pb(t_head	*head)
{
	prepend(&(head->stack_b), pop(&(head->stack_a)));
	write(1, "pb\n", 3);
}

void	pa(t_head	*head)
{
	prepend(&(head->stack_a), pop(&(head->stack_b)));
	write(1, "pa\n", 3);
}
