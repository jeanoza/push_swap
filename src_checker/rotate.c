/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:35:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 17:55:34 by kychoi           ###   ########.fr       */
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
}

void	rb(t_head *head)
{
	rotate(&(head->stack_b));
}

void	rr(t_head *head)
{
	rotate(&(head->stack_a));
	rotate(&(head->stack_b));
}
