/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:38:52 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 23:52:31 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_all_space(char *str)
{
	size_t	i;
	int		flag;

	flag = 1;
	i = 1;
	while (str[i])
	{
		if (!(str[i] >= 7 && str[i] <= 13))
		{
			break ;
			flag = 0;
		}
		i++;
	}
	return (flag);
}

void	set_space(char *ans)
{
	size_t	i;

	i = 0;
	while (ans[i])
	{
		if ((ans[i] >= 7 && ans[i] <= 13))
			ans[i] = ' ';
		i++;
	}
}

int	init_data(t_push_swap *data, char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	data->a = NULL;
	data->b = NULL;
	data->ans = NULL;
	data->temp = NULL;
	while (i < argc)
	{
		if (!argv[i] || ft_strlen(argv[i]) == 0 || is_all_space(argv[i]))
			return (-1);
		i++;
	}
	data->ans = loopjoin(argv, argc);
	set_space(data->ans);
	data->temp = ft_split(data->ans, ' ');
	data->max_index = 0;
	return (1);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;

	if (init_data(&data, argv, argc) == -1 || ft_strlen(data.ans) == 1)
		ft_error(data);
	if (!check(data.temp) || !*data.temp)
		ft_error(data);
	data.max_index = fill_a(&data.a, data.temp);
	if (data.max_index == -1)
		ft_error(data);
	if (!is_sort(data.a))
	{
		pre_sort(data);
		sort(&data);
	}
	cleardata(data);
	exit(0);
}
