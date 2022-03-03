/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:35:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 15:20:30 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
}

void	ra(t_head *head)
{
	rotate(&(head->stack_a));
	write(1, "ra\n", 3);
}

void	rb(t_head *head)
{
	rotate(&(head->stack_b));
	write(1, "rb\n", 3);
}

void	rr(t_head *head)
{
	rotate(&(head->stack_a));
	rotate(&(head->stack_b));
	write(1, "rr\n", 3);
}
