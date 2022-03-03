/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:35:25 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 21:04:02 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_a(t_head *head)
{
	int		pivots[3];

	find_pivots(head->stack_a, 5, pivots);
	while (stack_length(head->stack_b) < 2)
	{
		if (head->stack_a->num < pivots[0])
			pb(head);
		else
			ra(head);
	}
	if (head->stack_b->num < head->stack_b->next->num)
		sb(head);
	sort_three_a(head);
	pa(head);
	pa(head);
}

int	main(int ac, char **av)
{
	t_head	*head;

	head = init(ac - 1, av + 1);
	if (stack_length(head->stack_a) == 5)
		sort_five_a(head);
	else
		a_to_b(head, stack_length(head->stack_a));
	free_stack(head->stack_a);
	free(head);
	return (EXIT_SUCCESS);
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