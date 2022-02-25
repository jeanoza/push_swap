/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:57:07 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/08 20:38:57y kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_head *head, int *count)
{
	rotate(&(head->stack_a));
	if (count)
		*count += 1;
	write(1, "ra\n", 3);
}

void	rb(t_head *head, int *count)
{
	rotate(&(head->stack_b));
	if (count)
		*count += 1;
	write(1, "rb\n", 3);
}

void	rr(t_head *head, int *count_a, int *count_b)
{
	rotate(&(head->stack_a));
	rotate(&(head->stack_b));
	if (count_a)
		*count_a += 1;
	if (count_b)
		*count_b += 1;
	write(1, "rr\n", 3);
}
