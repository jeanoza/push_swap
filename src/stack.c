/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 22:06:57 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/03/03 13:09:54 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_desc(t_stack *stack, int count)
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

int	is_asc(t_stack *stack, int count)
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
