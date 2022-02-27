/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:55:36 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/27 12:47:40 by kyubongchoi      ###   ########.fr       */
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

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	stack = NULL;
	i = 0;
	while (i < ac)
		append(&stack, new_stack(atoi(av[i++])));
	return (stack);
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
