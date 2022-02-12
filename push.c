/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:05:53 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/12 20:34:48 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*first;
	t_stack	*last;

	first = *src;
	if (first == NULL)
		return ;
	last = first->prev;
	*src = first->next;
	if (*(src) == first)
		*src = NULL;
	else
	{
		(*src)->prev = last;
		last->next = *src;
	}
	first->prev = NULL;
	first->next = NULL;
	prepend_stack(dst, first);
}

void	pb(t_head	*head)
{
	push(&(head->stack_a), &(head->stack_b));
	write(1, "pb\n", 3);
}

void	pa(t_head	*head)
{
	push(&(head->stack_b), &(head->stack_a));
	write(1, "pa\n", 3);
}
