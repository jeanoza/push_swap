/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/11 12:46:58 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_stack *stack1, t_stack *stack2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		trigger;

	tmp1 = stack1;
	tmp2 = stack2;
	trigger = 0;
	write(1, "\n>> Print stacks:\n", 18);
	while (tmp1 || tmp2)
	{
		if ((trigger == 1 && (tmp1 == NULL || tmp2 == NULL)) || trigger == 2)
		{
			write(1, "- - -\na  b\n", 11);
			break ;
		}
		if (tmp1)
		{
			printf("%d ", tmp1->num);
			if (tmp1->next == stack1)
				++trigger;
			tmp1 = tmp1->next;
		}
		if (tmp2)
		{
			printf("%d ", tmp2->num);
			if (tmp2->next == stack2)
				++trigger;
			tmp2 = tmp2->next;
		}
		putchar('\n');
	}
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	int *arr = init_array(ac - 1, av + 1);
	free(arr);
	stack_a = init_stack(ac - 1, av + 1);
	stack_b = NULL;

	push(&stack_a, &stack_b, 0);

	print(stack_a, stack_b);
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