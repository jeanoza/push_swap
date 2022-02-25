/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:36:49 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/25 19:54:39 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		a_to_b_count3(head);
	}
	if (is_asc(head->stack_a, count))
	{
		printf("(check_stack_a -> is_asc) here2, count:%d\n", count);
		return (1);
	}
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

    init_array(head->stack_a, head, 0);
    printf("(a_to_b)1 count:%d median:%d small:%d big:%d\n", count, head->sorted_arr[head->median_idx], head->sorted_arr[head->small_idx], head->sorted_arr[head->big_idx]);
    print(head);

    if (check_stack_a(head, count))
    {
        printf("check stack_a\n");
        printf("max_test:%d\n", max_num(head->stack_a, 3));
        return;
    }
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
    printf("(a_to_b)2 ra:%d rb:%d pb:%d \n", ra_count, rb_count, pb_count);
    clean_up_stack(head, ra_count, rb_count);
    a_to_b(head, ra_count);
    b_to_a(head, rb_count);
    b_to_a(head, pb_count - rb_count);
}
//clean
//a_to_b(ra)
//b_to_a(rb)
//b_to_a(pb-rb)

