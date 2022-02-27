/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/27 17:41:03 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: print pre-sort array
void	print_array(int *arr, int size, int *pivots)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i == 0)
			printf("\nPre-sort:\n[");
		if (i == size - 1)
			printf("%d]\n", arr[i]);
		else
			printf("%d, ", arr[i]);
	}
	printf("pivots) median: %d	small: %d	big: %d\n",
		pivots[0], pivots[1], pivots[2]);
}

/*!
 * @note this void function is to init sorted_arr in @struct head
 * @param stack 
 * @param head 
 * @param size 
 */
//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
void	init_array(t_stack *stack, int size, int *pivots)
{
	int		i;
	int		*arr;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = -1;
	while (++i < size)
	{
		arr[i] = stack->num;
		stack = stack->next;
	}
	quick_sort(arr, 0, size - 1);
	pivots[0] = arr[(size - 1) / 2];
	pivots[1] = arr[(size - 1) / 4];
	pivots[2] = arr[(size - 1) / 2 + (size - 1) / 4 + 1];
	if (size == 1)
		pivots[2] = arr[0];
	free(arr);
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->stack_a = init_stack(ac, av);
	head->stack_b = NULL;
	return (head);
}