/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:52 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 17:00:20 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initdata(t_push_swap *data, char **argv, int argc)
{
	if (argc == 1)
		exit(0);
	data->a = NULL;
	data->b = NULL;
	data->ans = loopjoin(argv, argc);
	data->temp = ft_split(data->ans, ' ');
	data->max_index = 0;
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	initdata(&data, argv, argc);
	if (ft_strlen(data.ans) == 1)
		ft_error(data);
	if (!check(data.temp))
	{
		ft_error(data);
		return (0);
	}
	data.max_index = fill_a(&data.a, data.temp);
	if (data.max_index == -1)
	{
		ft_error(data);
		return (0);
	}
	if (!is_sort(data.a))
	{
		pre_sort(data);
		sort(&data);
	}
	cleardata(data);
	exit(0);
}
