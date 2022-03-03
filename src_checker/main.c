/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:08:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 21:19:59 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	operation(char *op, t_head *head)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(head);
	if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(head);
	if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(head);
	if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(head);
	if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(head);
	if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(head);
	if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(head);
	if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(head);
	if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(head);
	if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(head);
	if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(head);
}

int	main(int ac, char **av)
{
	t_head	*head;
	char	*op;

	head = init(ac - 1, av + 1);
	op = get_next_line(0);
	while (op != NULL)
	{
		operation(op, head);
		free(op);
		op = get_next_line(0);
	}
	if (head->stack_b == NULL
		&& is_asc(head->stack_a, stack_length(head->stack_a)))
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
	free_stack(head->stack_a);
	free(head);
	return (EXIT_SUCCESS);
}

//compile
//gcc -I./lib/libft -I./include -c ./src_checker/*.c
//gcc *.o -L./lib/libft/ -lft -o checker
//gcc main.o -L./lib/libft -lft -o checker
//./push_swap $ARG | ./checker ${ARG}
//system("leaks checker");

	// int		i;
	// t_stack	*tmp;
	// i = 0;
	// tmp = head->stack_a;
	// while (i == 0 || tmp != head->stack_a)
	// {
	// 	printf("tmp[%p]:%d\n", tmp, tmp->num);
	// 	tmp = tmp->next;
	// 	++i;
	// }