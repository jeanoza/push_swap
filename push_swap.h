/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:06:12 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/12 19:28:36 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

//TODO:Remove this libs...
# include <stdio.h>
# include <string.h>

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

/* stack.c */
t_stack	*new_stack(int num);
void	append_stack(t_stack **stack_list, t_stack *new_stack);
void	prepend_stack(t_stack **stack_list, t_stack *new_stack);
t_stack	*init_stack(int ac, char **av);
void	free_stack(t_stack *stack);

/* order.c */
void	swap(t_stack *stack, char opt);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack, char opt);
void	reverse_rotate(t_stack **stack, char opt);

void	pb(t_head	*head);

/* head.c */
t_head	*init_head(t_stack *stack_a, t_stack *stack_b);

/* quick_sort.c */
int		*init_array(int ac, char **av);

#endif
