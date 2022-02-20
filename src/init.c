/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/20 13:48:17 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FIXME: print pre-sort array
void	print_array(int *arr, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (i == 0)
			printf("\nPre-sort:\n[%d, ", arr[i]);
		else if (i == size - 1)
			printf("%d]\n", arr[i]);
		else
			printf("%d, ", arr[i]);
	}
	printf("size: %d\nmedian: %d\n", size, arr[size / 2]);

}
void	init_array(t_stack *stack, t_head *head)
{
	int		size;
	t_stack	*tmp;
	int		i;

	size = stack_length(stack);
	if (head->sorted_arr)
		free(head->sorted_arr);
	head->sorted_arr = malloc(sizeof(int) * size);
	if (!head->sorted_arr)
		return ;
	//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
	i = -1;
	tmp = stack;
	while (++i == 0 || tmp != stack)
	{
		head->sorted_arr[i] = tmp->num;
		tmp = tmp->next;
	}
	quick_sort(head->sorted_arr, 0, size - 1);
	head->median_idx = (size - 1) / 2;
	// print_array(head->sorted_arr, size);
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