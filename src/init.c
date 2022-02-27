/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 16:43:36 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: print pre-sort array
void	print_array(t_head *head, int size, int *pivots)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i == 0)
			printf("\nPre-sort:\n[");
		if (i == size - 1)
			printf("%d]\n", head->sorted_arr[i]);
		else
			printf("%d, ", head->sorted_arr[i]);
	}
	printf("pivots) median: %d	small: %d	big: %d\n", pivots[0], pivots[1], pivots[2]);
}

/*!
 * @note this void function is to init sorted_arr in @struct head
 * @param stack 
 * @param head 
 * @param size 
 */
//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
void	init_array(t_stack *stack, t_head *head, int size, int *pivots)
{
	t_stack	*tmp;
	int		i;

	head->sorted_arr = malloc(sizeof(int) * size);
	if (!head->sorted_arr)
		return ;
	i = -1;
	tmp = stack;
	while (++i == 0 || tmp != stack)
	{
		head->sorted_arr[i] = tmp->num;
		tmp = tmp->next;
	}
	quick_sort(head->sorted_arr, 0, size - 1);
	pivots[0] = head->sorted_arr[(size - 1) / 2];
	pivots[1] = head->sorted_arr[(size - 1) / 4];
	pivots[2] = head->sorted_arr[(size - 1) / 2 + (size - 1) / 4 + 1];
	if (size == 1)
		pivots[2] = head->sorted_arr[0];
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->stack_a = init_stack(ac, av);
	head->stack_b = NULL;
	return (head);
}