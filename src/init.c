/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/19 14:31:42 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*init_array(int ac, char **av)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * ac);
	i = -1;
	//TODO:data validation to add in 'ft_atoi' ex:if !digit => ERROR && EXIT
	while (++i < ac)
		arr[i] = atoi(av[i]);
	quick_sort(arr, 0, ac - 1);
	//FIXME: print pre-sort array
	// i = -1;
	// while (++i < ac)
	// {
	// 	if (i == 0)
	// 		printf("\nPre-sort:\n[%d, ", arr[i]);
	// 	else if (i == ac - 1)
	// 		printf("%d]\n", arr[i]);
	// 	else
	// 		printf("%d, ", arr[i]);
	// }
	// printf("length: %d\nmedian: %d\n", ac, arr[ac / 2]);
	return (arr);
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	head = malloc(sizeof(t_head));
	head->sorted_arr = init_array(ac, av);
	head->median = (head->sorted_arr)[ac / 2];
	head->median_idx = ac / 2;
	head->length = ac;
	head->stack_a = init_stack(ac, av);
	head->stack_b = NULL;
	return (head);
}