/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/19 10:56:35 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	if (stack->next == NULL)
		return (1);
	else
	{
		count = 0;
		tmp = stack;
		while (count == 0 || tmp != stack)
		{
			++count;
			tmp = tmp->next;
		}
	}
	return (count);
}

int	a_is_sorted(t_head *head, int start_idx)
{
	t_stack	*tmp;

	tmp = head->stack_a;
	while (tmp && start_idx < head->length)
	{
		if ((head->sorted_arr)[start_idx] != tmp->num)
			return (0);
		++start_idx;
		tmp = tmp->next;
	}
	return (1);
}

void	b_to_a(t_head *head, int pivot, t_stack *last)
{
	if (head->stack_b == last)
	{
		a_to_b(head, head->stack_a->prev->num, head->stack_a->prev);
		return ;
	}
	if (head->stack_b->num > pivot)
	{
		pa(head);
		if (stack_length(head->stack_a) > 1)
		{
			if (head->stack_a->num < head->stack_a->next->num)
				sa(head);
		}
	}
	else
		rb(head);
	b_to_a(head, pivot, last);
}

void	a_to_b(t_head *head, int pivot, t_stack *last)
{
	if (stack_length(head->stack_b) == 1)
	{
		if (a_is_sorted(head, 1))
			return ;
		else
			last = head->stack_a->prev;
	}
	if (head->stack_a == last)
	{
		b_to_a(head, head->stack_b->prev->num, head->stack_b->prev);
		return ;
	}
	if (head->stack_a->num < pivot)
	{
		pb(head);
		if (stack_length(head->stack_b) > 1)
		{
			if (head->stack_b->num < head->stack_b->next->num)
				sb(head);
		}
	}
	else
		ra(head);
	a_to_b(head, pivot, last);
}
