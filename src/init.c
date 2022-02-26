/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/26 15:54:01 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: print pre-sort array
void	print_array(t_head *head)
{
	int		i;

	i = -1;
	while (++i < head->length)
	{
		if (i == 0)
			printf("\nPre-sort:\n[");
		if (i == head->length - 1)
			printf("%d]\n", head->sorted_arr[i]);
		else
			printf("%d, ", head->sorted_arr[i]);
	}
	printf("size: %d median: %d small: %d big: %d\n", head->length, head->sorted_arr[head->median_idx], head->sorted_arr[head->small_idx], head->sorted_arr[head->big_idx]);
}

/*!
 * @note this void function is to init sorted_arr in @struct head
 * @param stack 
 * @param head 
 * @param size 
 */
//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
void	init_array(t_stack *stack, t_head *head, int size, int pivots[])
{
	t_stack	*tmp;
	int		i;

	// if (size != head->ac)
	// 	free(head->sorted_arr);
	// head->sorted_arr = malloc(sizeof(int) * size);
	// if (!head->sorted_arr)
	// 	return ;
	i = -1;
	tmp = stack;
	while (++i == 0 || tmp != stack)
	{
		head->sorted_arr[i] = tmp->num;
		tmp = tmp->next;
	}
	quick_sort(head->sorted_arr, 0, size - 1);
	// head->median_idx = (size - 1) / 2;
	// head->small_idx = (size - 1) / 4;
	// head->big_idx = head->median_idx + head->small_idx + 1;
	// (*pivots)[0] = (size - 1) / 2;
	// (*pivots)[1] = (size - 1) / 4;
	// (*pivots)[1] = (*pivots)[0] + (*pivots)[1] + 1;
	pivots[0] = (size - 1) / 2;
	pivots[1] = (size - 1) / 4;
	pivots[2] = pivots[0] + pivots[1] + 1;

	if (size == 1)
		pivots[1] = 0;
		// (*pivots)[1] = 0;
		// head->big_idx = 0;
	head->length = size;
	// free(head->sorted_arr);
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->stack_a = init_stack(ac, av);
	head->stack_b = NULL;
	head->ac = ac;
	return (head);
}