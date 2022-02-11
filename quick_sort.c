/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:39:35 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/11 11:54:37 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

static void	quick_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	partition(int *arr, int pivot, int left, int right)
{
	int index;
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

static int *quick_sort(int *arr, int left, int right)
{
	int	pivot;
	int index;

	if (left < right)
	{
		pivot = right;
		index = partition(arr, pivot, left, right);
		quick_sort(arr, left, index - 1);
		quick_sort(arr, index + 1, right);
	}
	return (arr);
}

int	*init_array(int ac, char **av)
{
	int *arr;
	int	i;

	arr = malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		arr[i] = atoi(av[i]);
	quick_sort(arr, 0, ac);
	printf("\nInit array(elements num:%d, median:%d)\n", ac, arr[ac / 2]);
	i = 0;
	while (arr[i])
		printf("%d ", arr[i++]);
	putchar('\n');
	return (arr);

}
