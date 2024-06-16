/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:48:30 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 17:50:59 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_node(t_stack **node, int value)
{
	t_stack	*cur;
	t_stack	*new_node;

	cur = *node;
	new_node = malloc(sizeof(t_stack) * 1);
	if (new_node == NULL)
		return (-1);
	new_node->value = value;
	new_node->next = NULL;
	new_node->index = -1;
	if (*node == NULL)
		*node = new_node;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new_node;
	}
	return (1);
}

t_stack	*find_last(t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	if (cur == NULL)
		return (NULL);
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}

t_stack	*find_before_last(t_stack **stack)
{
	t_stack	*cur;

	cur = *stack;
	while (cur->next->next != NULL)
		cur = cur->next;
	return (cur);
}

int	fill_a(t_stack **a, char **data)
{
	long	value;
	size_t	i;

	i = 0;
	while (data[i])
	{
		value = ft_atol(data[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (-1);
		if (add_node(a, value) == -1)
			return (-1);
		i++;
	}
	if (!is_duplicate(*a))
		return (-1);
	return (i);
}

int	list_count(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

/*
//--------------for debug----------------//
void	print_list(t_stack *stack)
{
	while (stack)
	{
		printf("Value of stack is %d\n",stack->value);
		stack = stack->next;
	}
}

void	print_list_index(t_stack *stack)
{
	while (stack)
	{
		printf("Index of stack is %d\n",stack->index);
		stack = stack->next;
	}
}
*/
