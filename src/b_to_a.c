/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:40:15 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/25 21:10:43 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_to_a_count3(t_head *head)
{
	pa(head, NULL);
	pa(head, NULL);
	pa(head, NULL);
	a_to_b(head, 3);
}

int		check_stack_b(t_head *head, int count)
{
	if (count == 3)
	{
		b_to_a_count3(head);
		return (1);
	}
	if (count == 2 && is_asc(head->stack_b, count))
	{
		sb(head);
		pa(head, NULL);
		pa(head, NULL);
		return (1);
	}
	if (is_desc(head->stack_b, count))
	{
		while (count--)
			pa(head, NULL);
		return (1);
	}
	return (0);
}

void	b_to_a(t_head *head, int count)
{
	int ra_count;
	int	rb_count;
	int pa_count;
	
	ra_count = 0;
	rb_count = 0;
	pa_count = 0;

	init_array(head->stack_b, head, 0);
	printf("(b_to_a)1 count:%d median:%d small:%d big:%d\n", count, head->sorted_arr[head->median_idx], head->sorted_arr[head->small_idx], head->sorted_arr[head->big_idx]);
	print(head);
	if (check_stack_b(head, count))
	{
		printf("check stack_b\n");
		return;
	}
	while (count > 0)
	{
		// if (head->stack_b->num > head->sorted_arr[head->small_idx])
		if (head->stack_b->num > head->sorted_arr[head->median_idx])
		{
			pa(head, &pa_count);
			// if (head->stack_a->num <= head->sorted_arr[head->median_idx])
			if (head->stack_a->num <= head->stack_a->next->num)
				ra(head, &ra_count);
		}
		else
			rb(head, &rb_count);
		--count;
	}
	// printf("(b_to_a)2 ra:%d rb:%d pa:%d \n", ra_count, rb_count, pa_count);
	a_to_b(head, pa_count - ra_count);
	clean_up_stack(head, ra_count, rb_count);
	a_to_b(head, ra_count);
	b_to_a(head, rb_count);

}
//a_to_b(pa-ra)
//clean
//a_to_b(ra)
//b_to_a(rb)
