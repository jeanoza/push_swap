/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:56:05 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/12 19:30:33 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*init_head(t_stack *stack_a, t_stack *stack_b)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->stack_a = stack_a;
	head->stack_b = stack_b;
	return (head);
}
