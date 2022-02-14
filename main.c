/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/14 23:03:54 by kyubongchoi      ###   ########.fr       */
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

// void	b_to_a(t_head *head, int pivot, int count);
// void	a_to_b(t_head *head, int pivot, int count);
void	a_to_b(t_head *head, int pivot, t_stack *last);
void	b_to_a(t_head *head, int pivot, t_stack *last);

// void	a_to_b(t_head *head, int pivot, int count)
void	a_to_b(t_head *head, int pivot, t_stack *last)
{
	if (ft_stack_length(head->stack_a) == 1)
		return ;
	if (head->stack_a == last)
	{
		print(head);
		b_to_a(head, head->stack_b->prev->num, head->stack_b->prev);
		return ;
	}
	if (head->stack_a->num < pivot)
	{
		pb(head);
		// if (b_last && head->stack_b->num > b_last)
		// 	rb(head);
	}
	else
	{
		ra(head);
	}
	a_to_b(head, pivot, last);
}

// void	b_to_a(t_head *head, int pivot, int count)
void	b_to_a(t_head *head, int pivot, t_stack *last)
{
	if (ft_stack_length(head->stack_b) == 1)
	{
		return ;
	}
	if (head->stack_b->num == pivot)
	{
		print(head);
		a_to_b(head, head->stack_a->prev->num, head->stack_a->prev);
		return ;
	}
	if (head->stack_b < last)
	{
		// int a_last;
		// if (head->stack_a)
		// {
		// 	if (head->stack_a->prev)
		// 	{
		// 		a_last = head->stack_a->prev->num;
		// 	}
		// }
		// printf("a_last:%d head->stack_b:%d\n", a_last, head->stack_b->num);
		pa(head);
		// if (a_last && head->stack_a->num > a_last)
		// 	ra(head);
	}
	else
	{
		rb(head);
	}
	b_to_a(head, pivot, last);
}

//TODO:put validation function for input args
int	main(int ac, char **av)
{
	t_head	*head;
	t_stack	*last;

	head = init(ac - 1, av + 1);
	print(head);
	a_to_b(head, head->median, head->stack_a->prev);
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