/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 20:45:51 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	if (stack->next == stack)
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

void	counts_to_zero(int *first, int *second, int *third)
{
	*first = 0;
	*second = 0;
	*third = 0;
}

void	clean_up_stack(t_head *head, int count_a, int count_b)
{
	while (count_a > 0 && count_b > 0)
	{
		rrr(head);
		--count_a;
		--count_b;
	}
	while (count_a > 0)
	{
		rra(head);
		--count_a;
	}
	while (count_b > 0)
	{
		rrb(head);
		--count_b;
	}
}

int		is_desc(t_stack *stack, int count)
{
	while (stack && count > 1)
	{
		if (stack->num < stack->next->num)
			return (0);
		stack = stack->next;
		--count;
	}
	return (1);
}
int		is_asc(t_stack *stack, int count)
{
	while (stack && count > 1)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
		--count;
	}
	return (1);
}

int	min_num(t_stack *stack, int count)
{
	int		min;

	min = stack->num;
	while (count-- > 0)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}


int	max_num(t_stack *stack, int count)
{
	int		max;

	max = stack->num;
	while (count-- > 0)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}
