/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:51:46 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/01 22:20:40 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//TODO:Remove this libs...
#include <stdio.h>
#include <string.h>

void	init_stack(int ac, char **av, int **a, int **b)
{
	int	i;

	*a = malloc(sizeof(int) * ac);
	*b = malloc(sizeof(int) * ac);
	i = 0;
	while (i < ac)
	{
		(*a)[i] = atoi(av[i]);
		++i;
	}
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;

	init_stack(ac - 1, av + 1, &stack_a, &stack_b);

	int i = -1;
	while (++i < ac - 1)
		printf("(%d)%d\n", i, stack_a[i]);
		
	free(stack_a);
	free(stack_b);
	return (0);
}
