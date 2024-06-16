/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:32:16 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 13:53:47 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findmaxbit(t_push_swap *data)
{
	int	count;
	int	max;

	count = 0;
	max = data->max_index - 1;
	while (max)
	{
		max >>= 1;
		count++;
	}
	return (count);
}

void	radix(t_push_swap *data)
{
	int	max;
	t_stack	*cur;
	int	count;
	max = findmaxbit(data);
	while (max--)
	{
		cur = data->a;
		count = list_count(data->a);
		while (count)
		{
			data->a->index >>= 1;
			if ((data->a->index % 2) & 1)
				rotate(&data->a,"a\n");
			else
				push(&data->a,&data->b,"b\n");
			count--;
		}
		while (data->b)
			push(&data->b, &data->a,"a\n");
	}
	// print_list(data->a);
	// print_list(data->b);

}
