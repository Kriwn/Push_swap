/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:32:16 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 15:42:37 by krwongwa         ###   ########.fr       */
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
	int	i;
	int loop;

	loop = 0;
	max = findmaxbit(data);
	while (max >= loop && !is_sort(data->a))
	{
		i = 0;
		while (i < data->max_index)
		{
			if ((data->a->index>>loop & 1))
				rotate(&data->a,"a\n");
			else
				push(&data->a,&data->b,"b\n");
			i++;
		}
		while (data->b)
			push(&data->b, &data->a,"a\n");
		loop++;
	}
}
