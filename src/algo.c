/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/20 14:29:40 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	if (stack->next == stack)
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

int	a_is_sorted(t_head *head, int start_idx)
{
	t_stack	*tmp;
	int		i;

	tmp = head->stack_a;
	i = 0;
	while (i == 0 || tmp != head->stack_a)
	{
		if ((head->sorted_arr)[start_idx + i++] != tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

// void	b_to_a(t_head *head, int pivot, int count)
void	b_to_a(t_head *head, int pivot1, int pivot2, int count)
{
	// print(head);
	printf("(b_to_a)pivot1:%d pivot2:%d ra:%d rb:%d pa:%d pb:%d\n", pivot1, pivot2, head->ra, head->rb, head->pa, head->pb);
	if (count == 0)
	{
		// printf("(b_to_a)pivot1:%d pivot_b:%d ra:%d rb:%d pa:%d pb:%d\n", pivot1, pivot2, head->ra, head->rb, head->pa, head->pb);
		head->pb = 0;
		return ;
	}
	if (head->stack_b->num > pivot2)
	{
		pa(head);
		if (head->pa == 3)
			sort_three_a(head);
		// if (head->stack_a->num > pivot1)
		// 	ra(head);
	}
	else
	{
		rb(head);
	}
	b_to_a(head, pivot1, pivot2, count - 1);
}

// void	a_to_b(t_head *head, int pivot, int count)
void	a_to_b(t_head *head, int pivot1, int pivot2, int count)
{
	if (count == 0)
	{
		// printf("(a_to_b)pivot1:%d pivot2:%d ra:%d rb:%d pa:%d pb:%d\n", pivot1, pivot2, head->ra, head->rb, head->pa, head->pb);
		return ;
	}
	if (head->stack_a->num < pivot1)
	{
		pb(head);
		if (head->stack_b->num > pivot2)
			rb(head);
	}
	else
	{
		ra(head);
	}
	a_to_b(head, pivot1, pivot2, count - 1);
}
// if (stack_length(head->stack_b) == 1)
// {
// 	if (a_is_sorted(head, 1))
// 		return ;
// 	else
// 		last = head->stack_a->prev;
// }

		// head->median_idx += head->median_idx / 2;
		// 	return ;

		// while ((head->ra) > 0 && (head->rb) > 0)
		// {
		// 	rrr(head);
		// 	--head->ra;
		// 	--head->rb;
		// }
		// while ((head->ra) > 0)
		// {
		// 	rra(head);
		// 	--head->ra;
		// }
		// while ((head->rb) > 0)
		// {
		// 	rrb(head);
		// 	--head->rb;
		// }
		// print(head);
		// head->pb = 0;