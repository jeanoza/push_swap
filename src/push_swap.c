/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/10 09:54:09 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*!
 * init array every time a_to_b or b_to_a called, to get right pviots
 * @param stack 
 * @param size it depends on @param count in a_to_b() or b_to_a()
 * @param pivots pivots[0] = median, pivots[1] = small, pivots[2] = big
 */
void	find_pivots(t_stack *stack, int size, int *pivots)
{
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = -1;
	while (++i < size)
	{
		arr[i] = stack->num;
		stack = stack->next;
	}
	quick_sort(arr, 0, size - 1);
	pivots[0] = arr[(size - 1) / 2];
	pivots[1] = arr[(size - 1) / 4];
	pivots[2] = arr[(size - 1) / 2 + (size - 1) / 4 + 1];
	if (size == 1)
		pivots[2] = arr[0];
	free(arr);
}

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

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		if (next == stack)
			break ;
		current = next;
	}
}
