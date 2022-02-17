/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:57:33 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/13 11:58:46 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*print_stack(t_stack *curr, t_stack *first)
{
	printf("%d\t", curr->num);
	if (curr->next == first)
		return (NULL);
	return (curr->next);
}

void	print(t_head *head)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = head->stack_a;
	tmp2 = head->stack_b;
	printf("\n>> Print stacks:\n\n");
	while (tmp1 || tmp2)
	{
		if (tmp1)
			tmp1 = print_stack(tmp1, head->stack_a);
		else
			printf("\t");
		if (tmp2)
			tmp2 = print_stack(tmp2, head->stack_b);
		printf("\n");
	}
	printf("-\t-\na\tb\n\n");
}
