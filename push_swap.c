/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:52 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/07 21:33:09 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initdata(t_push_swap *data,char **argv,int argc)
{
	data->a = NULL;
	data->b = NULL;
	data->ans = loopjoin(argv, argc);
	data->temp = ft_split(data->ans, ' ');
}


int main(int argc, char **argv)
{
	t_push_swap data;

	/// brok new line;
	initdata(&data, argv, argc);
	if (argc < 2)
		ft_error(data);
	if (!check(data.temp))
	{
		ft_error(data);
		return (0);
	}
	if (!fill_a(&data.a,data.temp))
	{
		ft_error(data);
		return (0);
	}
	// if (!is_sort(data.a)) //need fix
	// {
	// 	// presort();
	// 	// sort(data);
	// }
	print_list(data.a);
	cleardata(data);
}
