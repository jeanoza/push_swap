/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyubongchoi <kyubongchoi@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:23:03 by kychoi            #+#    #+#             */
/*   Updated: 2022/02/25 14:32:47 by kyubongchoi      ###   ########.fr       */
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
	{
		sa(head);
	}
	else if (first < second && second > third && first > third)
	{
		rra(head);
	}
	else if (first > second && second < third && first > third)
	{
		ra(head, NULL);
	}
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
		printf("(is_desc) count:%d num:%d next->num:%d\n", count, tmp->num, tmp->next->num);
		if (tmp->num < tmp->next->num)
		{
			return (0);
		}
		tmp = tmp->next;
		--count;
	}
	return (1);
}
int		is_asc(t_stack *stack, int count)
{
	t_stack	*tmp;

	tmp = stack;
	printf("(is_asc) count:%d num:%d\n", count, tmp->num);
	while (tmp && count > 1)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
		--count;
	}
	return (1);
}

int		check_stack_b(t_head *head, int count)
{
	if (count == 2 && is_asc(head->stack_b, count))
	{
		sb(head);
		pa(head, (int*)((void *)0));
		pa(head, (int*)((void *)0));
		return (1);
	}
	return (0);
}

int		check_stack_a(t_head *head, int count)
{
	if (count == 2 && is_desc(head->stack_a, count))
		sa(head);
	if (count == 3 && stack_length(head->stack_a) == 3)
		sort_three_a(head);
	if (is_asc(head->stack_a, count))
		return (1);
	return (0);
}

void	b_to_a(t_head *head, int count)
{
	int ra_count;
	int	rb_count;
	int pa_count;
	
	ra_count = 0;
	rb_count = 0;
	pa_count = 0;

	init_array(head->stack_b, head, 0);
	printf("(b_to_a)1 count:%d median:%d small:%d big:%d\n", count, head->sorted_arr[head->median_idx], head->sorted_arr[head->small_idx], head->sorted_arr[head->big_idx]);
	print(head);
	if (check_stack_b(head, count))
	{
		return;
	}
	while (count > 0)
	{
		if (head->stack_b->num > head->sorted_arr[head->small_idx])
		{
			pa(head, &pa_count);
			if (head->stack_a->num <= head->sorted_arr[head->median_idx])
				ra(head, &ra_count);
		}
		else
			rb(head, &rb_count);
		--count;
	}
	printf("(b_to_a)2 ra:%d rb:%d pa:%d \n", ra_count, rb_count, pa_count);
	clean_up_stack(head, ra_count, rb_count);
	a_to_b(head, pa_count - ra_count);
	a_to_b(head, ra_count);
	b_to_a(head, rb_count);

}
//a_to_b(pa-ra)
//clean
//a_to_b(ra)
//b_to_a(rb)

void	a_to_b(t_head *head, int count)
{
	int ra_count;
	int	rb_count;
	int pb_count;

	ra_count = 0;
	rb_count = 0;
	pb_count = 0;

	init_array(head->stack_a, head, 0);
	printf("(a_to_b)1 count:%d median:%d small:%d big:%d\n", count, head->sorted_arr[head->median_idx], head->sorted_arr[head->small_idx], head->sorted_arr[head->big_idx]);
	print(head);

	if (check_stack_a(head, count))
	{
		print(head);
		return;
	}
	while (count > 0)
	{
		if (head->stack_a->num < head->sorted_arr[head->big_idx])
		{
			pb(head, &pb_count);
			if (head->stack_b->num >= head->sorted_arr[head->median_idx])
				rb(head, &rb_count);
		}
		else
			ra(head, &ra_count);
		--count;
	}
	printf("(b_to_a)2 ra:%d rb:%d pb:%d \n", ra_count, rb_count, pb_count);
	clean_up_stack(head, ra_count, rb_count);
	a_to_b(head, ra_count);
	b_to_a(head, rb_count);
	b_to_a(head, pb_count - rb_count);
}
//clean
//a_to_b(ra)
//b_to_a(rb)
//b_to_a(pb-rb)

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

*/