/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/19 15:20:12 by kychoi           ###   ########.fr       */
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
	int		i;

	tmp = head->stack_a;
	i = 0;
	while (i == 0 || tmp != head->stack_a)
	{
		if ((head->sorted_arr)[start_idx + i++] != tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	b_to_a(t_head *head, int pivot, t_stack *last)
{
	printf("(b_to_a)pivot:%d last:%d\n", pivot, last->num);
	print(head);
	if (head->stack_b->num > pivot)
	{
		pa(head);
	}
	else
		rb(head);
	if (head->stack_b == last)
	{
		// a_to_b(head, pivot, head->stack_a->prev);
		return ;
	}
	b_to_a(head, pivot, last);
}

void	a_to_b(t_head *head, int pivot, t_stack *last)
{
	printf("(a_to_b)pivot:%d last:%d\n", pivot, last->num);
	print(head);
	if (head->stack_a->num < pivot)
		pb(head);
	else
		ra(head);
	if (head->stack_a == last)
	{
		b_to_a(head, (head->sorted_arr)[head->median_idx], head->stack_b->prev);
		return ;
	}
	a_to_b(head, pivot, last);
}
// if (stack_length(head->stack_b) == 1)
// {
// 	if (a_is_sorted(head, 1))
// 		return ;
// 	else
// 		last = head->stack_a->prev;
// }

		// head->median_idx += head->median_idx / 2;
		// printf("median_idx:%d head->length:%d\n", head->median_idx, head->length);
		// if (head->median_idx > head->length - 1)
		// 	return ;