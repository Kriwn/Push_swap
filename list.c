/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:48:30 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 13:50:37 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack **node, int value)
{
	t_stack *cur = *node;
	t_stack *new_Node = malloc(sizeof(t_stack) * 1);

	new_Node->value = value;
	new_Node->next = NULL;
	new_Node->index = -1;
	if (*node == NULL)
		*node = new_Node;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new_Node;
	}
}

t_stack	*find_last(t_stack **stack)
{
	t_stack *cur;

	cur = *stack;
	if (cur == NULL)
		return (NULL);
	while (cur->next !=NULL)
		cur = cur->next;
	return (cur);
}

t_stack	*find_before_last(t_stack **stack)
{
	t_stack *cur;

	cur = *stack;

	while (cur->next->next != NULL)
		cur = cur->next;
	return (cur);
}


int	fill_a(t_stack **a,char **data)
{
	long	value;
	size_t	i;

	i = 0;
	while (data[i])
	{
		value = ft_atol(data[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (-1);
		add_node(a, value);
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
		a = a->next;
		count++;
	}

	return (count);
}

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
