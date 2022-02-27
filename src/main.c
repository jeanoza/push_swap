/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/23 08:39:35kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && (arg[i] != '-'))
			return (0);
		if (arg[i] == '-' && !ft_isdigit(arg[i + 1]))
			return (0);
		++i;
	}
	return (1);
}

int	is_duplicated(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size && arr[i])
	{
		if (num == arr[i])
			return (1);
		++i;
	}
	return (0);
}

void	exit_parse_error(int *arr)
{
	write(1, "Error\n", 6);
	free(arr);
	exit(EXIT_FAILURE);
}

//TODO:split function && parse

int	is_to_split(char *av0, int ac)
{
	int	i;
	int	count;

	(void)ac;
	i = 0;
	count = 0;
	while (av0[i])
	{
		if (av0[i] == ' ' && ft_isdigit(av0[i + 1]))
			++count;
		++i;
	}
	printf("count:%d ac:%d\n", count, ac);
	return (1);
}

int	*parse_av_to_arr(int ac, char **av)
{
	int	*arr;
	int	i;

	is_to_split(av[0], ac);


	arr = malloc(sizeof(int) * ac);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (is_valid_arg(av[i]) && !is_duplicated(arr, ac, ft_atoi(av[i])))
			arr[i] = ft_atoi(av[i]);
		else
			exit_parse_error(arr);
		++i;
	}
	return (arr);
}

int	main(int ac, char **av)
{
	t_head	*head;
	int		*arr;

	arr = parse_av_to_arr(ac - 1, av + 1);
	if (arr)
	{
		head = init(ac - 1, arr);
		a_to_b(head, stack_length(head->stack_a));
		free_stack(head->stack_a);
		free(head);
	}
	return (EXIT_SUCCESS);
}

/*
sa : swap a - swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1.
	The first element becomes the last one.
rb : rotate b - shift up all elements of stack b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1.
	The last element becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.
*/