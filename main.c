/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/12 21:44:11 by kychoi           ###   ########.fr       */
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

static void	print(t_head *head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = head->stack_a;
	tmp2 = head->stack_b;
	printf("\n>> Print stacks:\n\n");
	while (tmp1 || tmp2)
	{
		if (tmp1)
		{
			printf("%d\t", tmp1->num);
			tmp1 = tmp1->next;
			if (tmp1 == head->stack_a)
				tmp1 = NULL;
		}
		else
			printf("\t");
		if (tmp2)
		{
			printf("%d\t", tmp2->num);
			tmp2 = tmp2->next;
			if (tmp2 == head->stack_b)
				tmp2 = NULL;
		}
		printf("\n");
	}
	printf("-\t-\na\tb\n\n");
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_head	*head;

	head = init(ac - 1, av + 1);
	print(head);
	free_stack(head->stack_a);
	free_stack(head->stack_b);
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