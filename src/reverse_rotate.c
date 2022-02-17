/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:34:31 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/12 21:47:45 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_head *head)
{
	reverse_rotate(&(head->stack_a));
	write(1, "rra\n", 4);
}

void	rrb(t_head *head)
{
	reverse_rotate(&(head->stack_b));
	write(1, "rrb\n", 4);
}

void	rrr(t_head *head)
{
	reverse_rotate(&(head->stack_a));
	reverse_rotate(&(head->stack_b));
	write(1, "rrr\n", 4);
}
