/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:35:11 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 20:25:35 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_head *head)
{
	int		first;
	int		second;
	int		third;

	first = head->stack_a->num;
	second = head->stack_a->next->num;
	third = head->stack_a->next->next->num;
	if (first < second && second < third)
		return ;
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

static void	a_to_b_count3(t_head *head)
{
	if (is_asc(head->stack_a, 3))
		return ;
	if (head->stack_a->next->next->num == max_num(head->stack_a, 3))
	{
		sa(head);
		return ;
	}
	if (head->stack_a->num == max_num(head->stack_a, 3))
		sa(head);
	if (head->stack_a->num == min_num(head->stack_a, 3))
	{
		ra(head);
		sa(head);
		rra(head);
	}
	else
	{
		pb(head);
		sa(head);
		ra(head);
		pa(head);
		rra(head);
	}
}

static int	check_stack_a(t_head *head, int count)
{
	if (count == 2 && is_desc(head->stack_a, count))
		sa(head);
	if (count == 3 && stack_length(head->stack_a) == 3)
		sort_three_a(head);
	else if (count == 3)
		a_to_b_count3(head);
	if (is_asc(head->stack_a, count))
		return (1);
	return (0);
}

void	a_to_b(t_head *head, int count)
{
	int	pivots[3];
	int	ra_count;
	int	rb_count;
	int	pb_count;

	counts_to_zero(&ra_count, &rb_count, &pb_count);
	find_pivots(head->stack_a, count, pivots);
	if (check_stack_a(head, count))
		return ;
	while (count > 0)
	{
		if (head->stack_a->num < pivots[2] && ++pb_count)
		{
			pb(head);
			if (head->stack_b->num >= pivots[0] && ++rb_count)
				rb(head);
		}
		else if (head->stack_a->num >= pivots[2] && ++ra_count)
			ra(head);
		--count;
	}
	clean_up_stack(head, ra_count, rb_count);
	a_to_b(head, ra_count);
	b_to_a(head, rb_count);
	b_to_a(head, pb_count - rb_count);
}
//clean
//a_to_b(ra)
//b_to_a(rb)
//b_to_a(pb-rb)
