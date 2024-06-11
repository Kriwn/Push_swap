/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krwongwa <krwongwa@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:35:32 by krwongwa          #+#    #+#             */
/*   Updated: 2024/06/09 14:58:05 by krwongwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_push_swap data)
{
	write(2,"ERROR\n",6);
	cleardata(data);
	exit(0);
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

void	freelist(t_stack **node)
{
	t_stack *stack = *node;
	t_stack *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
	*node = NULL;
}

void	free2d(char **str)
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
