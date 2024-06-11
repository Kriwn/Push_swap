/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:02:23 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/12 02:36:18 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_min_index(t_stack *a)
{
	long	min;
	size_t	i;
	t_stack	*min_node;

	min = LONG_MAX;
	while (a)
	{
		if (a->index == -1 && a->value < min)
		{
			min = a->value;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}

void	pre_sort(t_push_swap data)
{
	int		index;
	t_stack	*lowest;
	index = 0;
	while (index < data.max_index)
	{
		lowest = find_min_index(data.a);
		lowest->index = index;
		index++;
	}
}


void find_two_min(t_push_swap **node)
{
	int	count;
	t_push_swap *data;
	int i;

	i == 0;
	data = *node;
	count = 0;
	while (count != 2)
	{
		if (data->a->index == 0 || data->a->index == 1)
		{
			push(&data->a,&data->b, "b\n");
			count++;
		}
		else
			rotate(&data->a,"a\n");
	}
}
