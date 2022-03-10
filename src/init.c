/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:22 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/10 13:19:14 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(int num)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->num = num;
		stack->next = stack;
		stack->prev = stack;
	}
	return (stack);
}

static void	append(t_stack **stack_list, t_stack *new_stack)
{
	if (!stack_list || !new_stack)
		return ;
	if (!*stack_list)
		*stack_list = new_stack;
	else
	{
		(*stack_list)->prev->next = new_stack;
		new_stack->prev = (*stack_list)->prev;
		new_stack->next = *stack_list;
		(*stack_list)->prev = new_stack;
	}
}

static void	init_stack(int ac, char **av, t_head *head)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			exit_parse_error(head, NULL, 0);
		tmp = ft_split(av[i], ' ');
		j = 0;
		while (tmp[j])
		{
			if (is_valid(tmp[j]) && !is_duplicated(head->stack_a, tmp[j]))
			{
				append(&head->stack_a, new_stack(ft_atoi(tmp[j])));
				free(tmp[j]);
			}
			else
				exit_parse_error(head, tmp, j);
			++j;
		}
		free(tmp);
		++i;
	}
}

t_head	*init(int ac, char **av)
{
	t_head	*head;

	if (ac == 0)
		exit(EXIT_FAILURE);
	head = malloc(sizeof(t_head));
	if (!head)
		return (NULL);
	head->stack_a = NULL;
	head->stack_b = NULL;
	init_stack(ac, av, head);
	return (head);
}
