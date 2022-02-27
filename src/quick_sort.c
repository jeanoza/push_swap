/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:39:35 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/27 22:04:35 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	partition(int *arr, int pivot, int left, int right)
{
	int	index;
	int	i;

	index = left;
	i = left;
	while (i < right)
	{
		if (arr[i] < arr[pivot])
		{
			quick_swap(arr, i, index);
			++index;
		}
		++i;
	}
	quick_swap(arr, right, index);
	return (index);
}

int	*quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int	index;

	if (left < right)
	{
		pivot = right;
		index = partition(arr, pivot, left, right);
		quick_sort(arr, left, index - 1);
		quick_sort(arr, index + 1, right);
	}
	return (arr);
}
