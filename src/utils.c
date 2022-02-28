/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:55:36 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/02/28 21:49:42 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *arg)
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

int	is_duplicated(t_stack *stack, char *str)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	if (tmp == NULL)
		return (0);
	i = 0;
	while (i == 0 || tmp != stack)
	{
		if (tmp->num == ft_atoi(str))
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	exit_parse_error(t_head *head, char **splitted, char *current)
{
	write(1, "Error\n", 6);
	if (current)
		free(current);
	if (splitted)
		free(splitted);
	if (head->stack_a)
		free_stack(head->stack_a);
	if (head)
		free(head);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		if (next == stack)
			break ;
		current = next;
	}
}

/*!
 * init array every time a_to_b or b_to_a called, to get right pviots
 * @param stack 
 * @param size it depends on @param count in a_to_b() or b_to_a()
 * @param pivots pivots[0] = median, pivots[1] = small, pivots[2] = big
 */
void	find_pivots(t_stack *stack, int size, int *pivots)
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
