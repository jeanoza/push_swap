/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/08 22:58:34 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack, char *title, char *stack_name)
{
	t_stack	*tmp;

	tmp = stack;
	write(1, title, strlen(title));
	write(1, "\n", 1);
	while (tmp != NULL)
	{
		printf("%s[%p]%d\n", stack_name, tmp, tmp->num);
		if (tmp->next == stack)
			break;
		tmp = tmp->next;
	}
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack(ac - 1, av + 1);
	stack_b = NULL;

	swap(stack_a, 0);
	push(&stack_a, &stack_b, 0);
	swap(stack_b, 1);
	free_stack(stack_a);
	free_stack(stack_b);

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