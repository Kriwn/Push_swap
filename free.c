/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:32 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/16 23:51:37 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	freelist(t_stack **node)
{
	t_stack	*stack;
	t_stack	*temp;

	stack = *node;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
	*node = NULL;
}

static void	free2d(char **str)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (str[i])
	{
		temp = str[i];
		free(temp);
		i++;
	}
	free(str);
}

void	ft_error(t_push_swap data)
{
	write(2, "Error\n", 6);
	cleardata(data);
	exit(1);
}

void	cleardata(t_push_swap data)
{
	if (data.ans)
		free(data.ans);
	if (data.temp)
		free2d(data.temp);
	if (data.a)
		freelist(&data.a);
	if (data.b)
		freelist(&data.b);
}
