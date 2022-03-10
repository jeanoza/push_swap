/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kychoi <kychoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:55:36 by kyubongchoi       #+#    #+#             */
/*   Updated: 2022/03/10 12:32:34 by kychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *arg)
{
	int		i;
	char	*res_atoi_to_itoa;

	res_atoi_to_itoa = ft_itoa(ft_atoi(arg));
	if (ft_strncmp(res_atoi_to_itoa, arg, ft_strlen(arg)) != 0)
	{
		free(res_atoi_to_itoa);
		return (0);
	}
	free(res_atoi_to_itoa);
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

void	exit_parse_error(t_head *head, char **splitted, int idx)
{
	write(1, "Error\n", 6);
	while (splitted[idx])
		free(splitted[idx++]);
	if (splitted)
		free(splitted);
	if (head->stack_a)
		free_stack(head->stack_a);
	if (head)
		free(head);
	exit(EXIT_FAILURE);
}
