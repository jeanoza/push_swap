/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:55:36 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/17 20:22:37 by kychoi           ###   ########.fr       */
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

void	append(t_stack **stack_list, t_stack *new_stack)
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

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;
	t_stack	*tmp;

	stack = NULL;
	i = 0;
	while (i < ac)
	{
		append(&stack, new_stack(atoi(av[i])));
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
