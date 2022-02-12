/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:55:36 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/12 21:01:23 by kychoi           ###   ########.fr       */
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
		stack->next = NULL;
		stack->prev = NULL;
	}
	return (stack);
}

void	append_stack(t_stack **stack_list, t_stack *new_stack)
{
	t_stack	*tmp;

	if (!*stack_list)
	{
		*stack_list = new_stack;
		return ;
	}
	tmp = *stack_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_stack;
	new_stack->prev = tmp;
}

void	prepend_stack(t_stack **stack_list, t_stack *new_stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_list)
	{
		*stack_list = new_stack;
		return ;
	}
	first = *stack_list;
	last = first->prev;
	new_stack->next = first;
	first->prev = new_stack;
	if (last == NULL)
	{
		first->next = new_stack;
		new_stack->prev = *stack_list;
	}
	else
	{
		last->next = new_stack;
		new_stack->prev = last;
	}
	*stack_list = new_stack;
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;

	stack = NULL;
	i = 0;
	while (i < ac)
	{
		append_stack(&stack, new_stack(atoi(av[i])));
		++i;
	}
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack;
	stack->prev = tmp;
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
