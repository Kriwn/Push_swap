/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:40:33 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/13 16:53:16 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *data)
{
	if (data->max_index == 2)
		sort_two(&data->a,"a\n");
	else if (data->max_index == 3)
		sort_three(&data->a, "a\n");
	else if (data->max_index == 4)
		sort_four(data);
	else if (data->max_index == 5)
		sort_five(data);
	else
		radix(data);
}

void	sort_two(t_stack **node,char *str)
{
	t_stack *data;

	data = *node;
	if (data->index > data->next->index)
		swap(node,str);
};

void	sort_three(t_stack **node, char *str)
{

	while (!is_sort(*node))
	{
		if (!is_sort(*node) && (*node)->index > (*node)->next->index)
			swap(node,str);
		if (!is_sort(*node) && (*node)->next->index > (*node)->next->next->index)
			reverse_rotate(node,str);
		if (!is_sort(*node) && (*node)->index > (*node)->next->next->index)
			rotate(node,str);
	}
}

void	sort_four(t_push_swap *data)
{
	while (1)
	{
		if (data->a->index == 0)
		{
			push(&data->a,&data->b, "b\n");
			break;
		}
		else
			rotate(&data->a,"a\n");
	}
	sort_three(&data->a,"a\n");
	push(&data->b, &data->a,"a\n");
}


// less than 12    not work some case
void	sort_five(t_push_swap *data)
{

	find_two_min(&data); // this one not work btw;
	sort_three(&data->a,"a\n");
	sort_two(&data->b,"b\n");
	swap(&data->b,"b\n");
	push(&data->b, &data->a,"a\n");
	push(&data->b, &data->a,"a\n");
}
