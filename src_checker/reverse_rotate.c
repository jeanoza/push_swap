/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:34:31 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 17:55:43 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	reverse_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->prev == NULL)
		return ;
	*stack = (*stack)->prev;
}

void	rra(t_head *head)
{
	reverse_rotate(&(head->stack_a));
}

void	rrb(t_head *head)
{
	reverse_rotate(&(head->stack_b));
}

void	rrr(t_head *head)
{
	reverse_rotate(&(head->stack_a));
	reverse_rotate(&(head->stack_b));
}
