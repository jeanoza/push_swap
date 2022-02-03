/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/04 00:46:49 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//TODO:Remove this libs...
#include <stdio.h>
#include <string.h>

typedef struct s_stack
{
	int				num;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

t_stack	*new_stack(int num)
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
void	swap(t_stack *stack)
{
}

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}
void	reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	next = NULL;
	while (current != NULL)
	{
		if (current->next == stack)
		{
			free(current);
			break;
		}
		next = current->next;
		free(current);
		current = next;
	}
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	t_stack	*last;

	stack_a = init_stack(ac - 1, av + 1);

	//test next
	printf("test next - stop at last\n");
	tmp = stack_a;
	while (tmp != NULL)
	{
		printf("(next)tmp[%p]%d - tmp->next[%p]\n",tmp, tmp->num, tmp->next);
		if (tmp->next == stack_a)
			break ;
		tmp = tmp->next;
	}

	//test prev
	last = tmp;
	printf("test prev - stop at first\n");
	while (tmp != NULL)
	{
		printf("(prev)tmp[%p]%d - tmp->prev[%p]\n",tmp, tmp->num, tmp->prev);
		if (tmp->prev == last)
			break ;
		tmp = tmp->prev;
	}

	//rotate
	rotate(&stack_a);
	tmp = stack_a;
	printf("after rotate - stop at last\n");
	while (tmp != NULL)
	{
		printf("(next)tmp[%p]%d - tmp->next[%p]\n",tmp, tmp->num, tmp->next);
		if (tmp->next == stack_a)
			break ;
		tmp = tmp->next;
	}

	//reverse rotate
	reverse_rotate(&stack_a);
	tmp = stack_a;
	printf("rra - stop at last\n");
	while (tmp != NULL)
	{
		printf("(next)tmp[%p]%d - tmp->next[%p]\n",tmp, tmp->num, tmp->next);
		if (tmp->next == stack_a)
			break ;
		tmp = tmp->next;
	}

	free_stack(stack_a);

	return (0);
}

/*
sa : swap a - swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1.
	The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.
*/