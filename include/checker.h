/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:59:24 by kychoi            #+#    #+#             */
/*   Updated: 2022/03/03 15:26:41 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //TODO:remove after test

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_head
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}	t_head;

/* init.c */
t_head	*init(int ac, char **av);

/* validation.c */
int		is_valid(char *arg);
int		is_duplicated(t_stack *stack, char *str);
void	exit_parse_error(t_head *head, char **splitted, char *current);

/* stack.c */
int		is_asc(t_stack *stack, int count);
int		is_desc(t_stack *stack, int count);
int		min_num(t_stack *stack, int count);
int		max_num(t_stack *stack, int count);

/* push_swap.c */
void	find_pivots(t_stack *stack, int size, int *pivots);
int		stack_length(t_stack *stack);
void	counts_to_zero(int *first, int *second, int *third);
void	clean_up_stack(t_head *head, int count_a, int count_b);
void	free_stack(t_stack *stack);

/* swap.c */
void	sa(t_head *head);
void	sb(t_head *head);
void	ss(t_head *head);

/* push.c */
void	pb(t_head *head);
void	pa(t_head *head);

/* rotate.c */
void	ra(t_head *head);
void	rb(t_head *head);
void	rr(t_head *head);

/* reverse_rotate.c */
void	rra(t_head *head);
void	rrb(t_head *head);
void	rrr(t_head *head);

#endif