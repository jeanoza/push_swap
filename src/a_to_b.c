/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:36:49 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/26 12:59:05 by kyubongchoi      ###   ########.fr       */
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
		ra(head, NULL);
	}
	else if (first > second && second < third && first < third)
		sa(head);
	else if (first < second && second > third && first > third)
		rra(head);
	else if (first > second && second < third && first > third)
		ra(head, NULL);
	else if (first > second && second > third)
	{
		ra(head, NULL);
		sa(head);
	}
}


void	a_to_b_count3(t_head *head)
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
		ra(head, NULL);
		sa(head);
		rra(head);
	}
	else
	{
		pb(head, NULL);
		sa(head);
		ra(head, NULL);
        pa(head, NULL);
		rra(head);
	}
}

int		check_stack_a(t_head *head, int count)
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
    int ra_count;
    int	rb_count;
    int pb_count;

    ra_count = 0;
    rb_count = 0;
    pb_count = 0;
	init_array(head->stack_a, head, count);
    if (check_stack_a(head, count))
        return;
    while (count > 0)
    {
        if (head->stack_a->num < head->sorted_arr[head->big_idx])
        {
            pb(head, &pb_count);
            if (head->stack_b->num >= head->sorted_arr[head->median_idx])
                rb(head, &rb_count);
        }
        else
            ra(head, &ra_count);
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

