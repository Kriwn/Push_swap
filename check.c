/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:17 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 22:08:23 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkdigit(size_t i, char *str)
{
	int	count;
	int	flag;

	flag = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			count++;
			if (str[i] != '0')
				flag = 0;
		}
		else
			return (0);
	}
	if (count > 10 && flag)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (!str[i] && (count > 0))
		return (1);
	else
		return (0);
}

static int	checkstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (checkdigit(i, str) == 0)
		return (0);
	return (1);
}

int	check(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (checkstr(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*temp;
	int		value;

	while (stack)
	{
		value = stack->value;
		temp = stack->next;
		while (temp)
		{
			if (value == temp->value)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	is_sort(t_stack *stack)
{
	int	value;

	value = stack->value;
	stack = stack->next;
	while (stack)
	{
		if (value > stack->value)
			return (0);
		value = stack->value;
		stack = stack->next;
	}
	return (1);
}
