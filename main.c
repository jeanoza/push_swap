/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/12 19:49:41 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_length(t_stack *stack)
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

void	print(t_stack *stack1, t_stack *stack2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack1;
	tmp2 = stack2;
	printf("\n>> Print stacks:\n\n");
	while (tmp1 || tmp2)
	{
		if (tmp1)
		{
			printf("tmp1\n");
			printf("[%p]%d\t", tmp1, tmp1->num);
			tmp1 = tmp1->next;
			if (tmp1 == stack1)
				tmp1 = NULL;
		}
		else
			printf("\t");
		if (tmp2)
		{
			printf("tmp2\n");
			printf("[%p]%d\t", tmp2, tmp2->num);
			tmp2 = tmp2->next;
			if (tmp2 == stack2)
				tmp2 = NULL;
		}
		printf("\n");
	}
	printf("-\t-\na\tb\n\n");
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_head	*head;
	int		*arr;

	arr = init_array(ac - 1, av + 1);
	free(arr);
	stack_a = init_stack(ac - 1, av + 1);
	stack_b = NULL;
	head = init_head(stack_a, stack_b);
	print(stack_a, stack_b);
	pb(head);
	printf("3)stack_a[%p]:%d stack_b[%p]\n", head->stack_a, head->stack_a->num, head->stack_b);
	printf("4)stack_a[%p]:%d stack_b[%p]\n", stack_a, stack_a->num, stack_b);
	print(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free(head);

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