/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:40:15 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 23:06:00 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_count3(t_head *head)
{
	pa(head);
	pa(head);
	pa(head);
	a_to_b(head, 3);
}

int	check_stack_b(t_head *head, int count)
{
	if (count == 3)
	{
		b_to_a_count3(head);
		return (1);
	}
	if (count == 2 && is_asc(head->stack_b, count))
	{
		sb(head);
		pa(head);
		pa(head);
		return (1);
	}
	if (is_desc(head->stack_b, count))
	{
		while (count--)
			pa(head);
		return (1);
	}
	return (0);
}

void	b_to_a(t_head *head, int count)
{
	int	pivots[3];
	int	ra_count;
	int	rb_count;
	int	pa_count;

	counts_to_zero(&ra_count, &rb_count, &pa_count);
	find_pivots(head->stack_b, count, pivots);
	if (check_stack_b(head, count))
		return ;
	while (count > 0)
	{
		if (head->stack_b->num > pivots[1] && ++pa_count)
		{
			pa(head);
			if (head->stack_a->num <= pivots[0] && ++ ra_count)
				ra(head);
		}
		else if (head->stack_b->num <= pivots[1] && ++rb_count)
			rb(head);
		--count;
	}
	a_to_b(head, pa_count - ra_count);
	clean_up_stack(head, ra_count, rb_count);
	a_to_b(head, ra_count);
	b_to_a(head, rb_count);
}
//a_to_b(pa-ra)
//clean
//a_to_b(ra)
//b_to_a(rb)
