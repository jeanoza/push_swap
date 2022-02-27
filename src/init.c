/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 23:35:36 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->num = num;
		stack->next = stack;
		stack->prev = stack;
	}
	return (stack);
}

static void	append(t_stack **stack_list, t_stack *new_stack)
{
	if (!stack_list || !new_stack)
		return ;
	if (!*stack_list)
		*stack_list = new_stack;
	else
	{
		(*stack_list)->prev->next = new_stack;
		new_stack->prev = (*stack_list)->prev;
		new_stack->next = *stack_list;
		(*stack_list)->prev = new_stack;
	}
}

static void	init_stack(int size, int *arr, t_head *head)
{
	int		i;

	head->stack_a = NULL;
	head->stack_b = NULL;
	i = 0;
	while (i < size)
	{
		append(&head->stack_a, new_stack(arr[i]));
		++i;
	}
	free(arr);
}


t_head	*init(int size, int *arr)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	if (!head)
		return (NULL);
	init_stack(size, arr, head);
	return (head);
}
