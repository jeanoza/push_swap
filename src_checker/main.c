/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:08:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/04 20:28:48 by kyubongchoi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <fcntl.h>

void	operation_error(char *op, t_head *head)
{
	free(op);
	write(1, "Error\n", 6);
	if (stack_length(head->stack_a) > 0)
		free_stack(head->stack_a);
	if (stack_length(head->stack_b) > 0)
		free_stack(head->stack_b);
	free(head);
	exit(EXIT_FAILURE);
}
void	operation(char *op, t_head *head)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(head);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(head);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(head);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(head);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(head);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(head);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(head);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(head);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(head);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(head);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(head);
	else
		operation_error(op, head);

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
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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