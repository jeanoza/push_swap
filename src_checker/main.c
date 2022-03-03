/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:08:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 16:57:19 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_head	*head;
	t_stack	*tmp;
	int		i;
	// char	*op;

	head = init(ac - 1, av + 1);
	tmp = head->stack_a;
	i = 0;
	while (i == 0 || tmp != head->stack_a)
	{
		printf("tmp[%p]:%d\n", tmp, tmp->num);
		tmp = tmp->next;
		++i;
	}
	// op = get_next_line(0);
	// while (op != NULL)
	// {
	// 	printf("op:%s\n", op);
	// 	free(op);
	// 	op = get_next_line(0);
	// }
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