/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:08:41 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 16:19:27 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_head	*head;
	char	*op;

	head = init(ac - 1, av + 1);
	op = get_next_line(0);
	while (op != NULL)
	{
		printf("op:%s\n", op);
		op = get_next_line(0);
	}
	return (EXIT_SUCCESS);
}

//compile
//gcc -I./lib/libft -I./include -c ./src_checker/*.c
//gcc *.o -L./lib/libft/ -lft -o checker
//gcc main.o -L./lib/libft -lft -o checker
//./push_swap $ARG | ./checker ${ARG}