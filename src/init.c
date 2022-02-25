/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/25 20:50:09 by kychoi           ###   ########.fr       */
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
 * @param already_exist  0 | 1 to verify if the array is already malloacated
 */
//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
void	init_array(t_stack *stack, t_head *head, char already_exist)
{
	int		size;
	t_stack	*tmp;
	int		i;

	if (already_exist)
		free(head->sorted_arr);
	size = stack_length(stack);
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
	head->median_idx = (size - 1) / 2;
	head->small_idx = (size - 1) / 4;
	head->big_idx = head->median_idx + head->small_idx + 1;
	if (size == 1)
		head->big_idx = 0;
	head->length = size;
	// print(head);
	print_array(head);
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->ra = 0;
	head->rb = 0;
	head->pa = 0;
	head->pb = 0;
	head->stack_a = init_stack(ac, av);
	head->stack_b = NULL;
	return (head);
}