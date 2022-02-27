/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 22:10:26 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counts_to_zero(int *first, int *second, int *third)
{
	*first = 0;
	*second = 0;
	*third = 0;
}

void	clean_up_stack(t_head *head, int count_a, int count_b)
{
	while (count_a > 0 && count_b > 0)
	{
		rrr(head);
		--count_a;
		--count_b;
	}
	while (count_a > 0)
	{
		rra(head);
		--count_a;
	}
	while (count_b > 0)
	{
		rrb(head);
		--count_b;
	}
}
