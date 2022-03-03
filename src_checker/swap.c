/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:08:35 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 17:55:24 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	sa(t_head	*head)
{
	swap(head->stack_a);
}

void	sb(t_head	*head)
{
	swap(head->stack_b);
}

void	ss(t_head	*head)
{
	swap(head->stack_a);
	swap(head->stack_b);
}
