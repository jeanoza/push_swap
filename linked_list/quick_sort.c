/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 23:39:35 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/11 00:07:20 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

void	swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int	partition(int *arr, int pivot, int left, int right)
{
	int index;
	int	i;

	index = left;
	i = left;
	while (i < right)
	{
		printf("pivot:%d left:%d right:%d index:%d i:%d\n", pivot, left, right, index, i);
		if (arr[i] < arr[pivot])
		{
			swap(arr, i, index);
			++index;
		}
		++i;
	}
	swap(arr, right, index);
	return (index);
}

int *quick_sort(int *arr, int left, int right)
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

int main(int ac, char **av)
{
	// int arr[10] = {2, 1, 4, 5, 3, 100};
	int *arr;
	int	i;

	--ac;
	++av;
	arr = malloc(sizeof(int) * ac);
	i = -1;
	while (++i < ac)
		arr[i] = atoi(av[i]);

	i = 0;
	write(1, "\nInit: ", 7);
	while (arr[i])
		printf("%d ", arr[i++]);
	putchar('\n');
	quick_sort(arr, 0, ac - 1);
	write(1, "\nAfter quicksort: ", 20);
	i = 0;
	while (arr[i])
		printf("%d ", arr[i++]);
	putchar('\n');
	free(arr);
	return (0);
}