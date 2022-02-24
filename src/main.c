/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/23 08:39:35kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO:put validation function for input args
void	sort_three_a(t_head *head)
{
	int		first;
	int		second;
	int		third;

	first = head->stack_a->num;
	second = head->stack_a->next->num;
	third = head->stack_a->next->next->num;
	if (first < second && second < third)
		;
	else if (first < second && second > third && first < third)
	{
		sa(head);
		ra(head);
	}
	else if (first > second && second < third && first < third)
		sa(head);
	else if (first < second && second > third && first > third)
		rra(head);
	else if (first > second && second < third && first > third)
		ra(head);
	else if (first > second && second > third)
	{
		ra(head);
		sa(head);
	}
}

int	main(int ac, char **av)
{
	t_head	*head;
	// int	ra_tmp;
	// int rb_tmp;
	int	i;

	head = init(ac - 1, av + 1);
	// init_array(head->stack_a, head, 0);
	// print(head);

	// i = 0;
	init_array(head->stack_a, head, 0);
	a_to_b(head, head->sorted_arr[head->median_idx],
		head->sorted_arr[head->median_idx / 2], stack_length(head->stack_a));
	print(head);

	// init_array(head->stack_b, head, 1);
	b_to_a(head, head->sorted_arr[head->median_idx],
		head->sorted_arr[head->median_idx / 2], head->pb);
	head->pb = 0;
	print(head);

	i = 1;
	int	pivot1;
	int	pivot2;
	while (i < 10)
	{
		pivot1 = head->sorted_arr[head->median_idx / i];
		pivot2 = head->sorted_arr[head->median_idx / (i * 2)];
		// init_array(head->stack_a, head, 1);
		a_to_b(head, pivot1, pivot2, stack_length(head->stack_a));
		head->pa = 0;
		print(head);

		// init_array(head->stack_b, head, 1);
		a_to_b(head, pivot1, pivot2, head->pb);
		head->pb = 0;
		print(head);

		++i;
	}



	free_stack(head->stack_a);
	// free_stack(head->stack_b);
	free(head->sorted_arr);
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