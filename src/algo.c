/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/25 19:53:54 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	if (stack == NULL)
		return (0);
	if (stack->next == stack)
		return (1);
	else
	{
		count = 0;
		tmp = stack;
		while (count == 0 || tmp != stack)
		{
			++count;
			tmp = tmp->next;
		}
	}
	return (count);
}

void	clean_up_stack(t_head *head, int count_a, int count_b)
{
	while (count_a > 0 && count_b > 0)
	{
		rrr(head);
		--count_a;
		--count_b;
	}
	while (count_a > 0)
	{
		rra(head);
		--count_a;
	}
	while (count_b > 0)
	{
		rrb(head);
		--count_b;
	}
}

void	sort_three_a(t_head *head)
{
	int		first;
	int		second;
	int		third;

	first = head->stack_a->num;
	second = head->stack_a->next->num;
	third = head->stack_a->next->next->num;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		sa(head);
		ra(head, NULL);
	}
	else if (first > second && second < third && first < third)
		sa(head);
	else if (first < second && second > third && first > third)
		rra(head);
	else if (first > second && second < third && first > third)
		ra(head, NULL);
	else if (first > second && second > third)
	{
		ra(head, NULL);
		sa(head);
	}
}


int		is_desc(t_stack *stack, int count)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && count > 1)
	{
		printf("\n(is_desc) count:%d num:%d next->num:%d\n", count, tmp->num, tmp->next->num);
		if (tmp->num < tmp->next->num)
			return (0);
		tmp = tmp->next;
		--count;
	}
	return (1);
}
int		is_asc(t_stack *stack, int count)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && count > 1)
	{
		printf("\n(is_asc) count:%d num:%d next->num:%d\n", count, tmp->num, tmp->next->num);
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
		--count;
	}
	return (1);
}

int	min_num(t_stack *stack, int count)
{
	int		min;

	if (count <= 0)
		return (-1);
	min = stack->num;
	while (count-- > 0)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}


int	max_num(t_stack *stack, int count)
{
	int		max;

	if (count <= 0)
		return (-1);
	max = stack->num;
	while (count-- > 0)
	{
		if (stack->num > max)
			max = stack->num;
		stack = stack->next;
	}
	return (max);
}

/*

int	ft_return_a_to_b(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 2 && ft_check_descending(*stack_a, count))
		ft_sa(*stack_a);
	if (count == 3 && ft_size_node(*stack_a) == 3)
		ft_stack_3(stack_a);
	else if (count == 3)
		ft_stack_3_a_to_b(stack_a, stack_b);
	if (ft_check_ascending(*stack_a, count))
		return (1);
	return (0);
}

int	ft_return_b_to_a(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (count == 3)
	{
		ft_stack_3_b_to_a(stack_a, stack_b);
		return (1);
	}
	if (count == 2 && ft_check_ascending(*stack_b, count))
	{
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	if (ft_check_descending(*stack_b, count))
	{
		while (count--)
			ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}
void	ft_stack_3_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_ascending(*stack_a, 3))
		return ;
	if ((*stack_a)->next->next->num == ft_max_size(*stack_a, 3))
	{
		ft_sa(*stack_a);
		return ;
	}
	if ((*stack_a)->num == ft_max_size(*stack_a, 3))
		ft_sa(*stack_a);
	if ((*stack_a)->num == ft_min_size(*stack_a, 3))
	{
		ft_ra(stack_a);
		ft_sa(*stack_a);
		ft_rra(stack_a);
	}
	else
	{
		ft_pb(stack_b, stack_a);
		ft_sa(*stack_a);
		ft_ra(stack_a);
		ft_pa(stack_a, stack_b);
		ft_rra(stack_a);
	}
}
void	ft_stack_3_b_to_a(t_stack **stack_a, t_stack **stack_b)
{	
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_a_to_b(stack_a, stack_b, 3);
}


*/