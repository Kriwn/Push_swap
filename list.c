/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 15:48:30 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 13:35:24 by krwongwa         ###   ########.fr       */
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
			return (0);
		add_node(a, value);
		i++;
	}
	if (!is_duplicate(*a))
		return (0);
	return (1);
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
